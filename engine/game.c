#include "rogue.h"
#include "utils.h"
#include <string.h>

game_t*
game_init()
{
    game_t* game         = (game_t*)malloc(sizeof(game_t));
    game->map            = tile_map_init();
    game->player         = player_init();
    game->messages_count = 0;
    game->items          = item_list_init();
    memset(game->messages, 0, MAX_MESSAGES);
    generate_items(game);
    calculate_light(game->map, game->player);
    return game;
}

void
game_input(game_t* game, char key)
{
    switch (key) {
        case 'h':
        case 'j':
        case 'k':
        case 'l':
        case 'y':
        case 'n':
        case 'b':
        case 'u':
            player_try_move(game->player, game->map, key);
            calculate_light(game->map, game->player);
            break;
        case ',': {
            item_t* found = player_try_pickup(game->player, game->items);
            if (found != NULL) {
                game_message(game, "Picked up %s\n", found->name);
            } else {
                game_message(game, "There's nothing to pickup here.\n");
            }
        } break;
        default:
            game_message(game, "Sorry. '%c' is not a valid key!\n", key);
    }
}

void
game_message(game_t* game, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vsnprintf(
      game->messages[game->messages_count].buf, MESSAGE_SIZE, fmt, args);
    game->messages_count++;
    // Probably not good, but for now, let's just limit the message
    // list to just 1024. We'll see.
    if (game->messages_count > MAX_MESSAGES)
        game->messages_count = 0;
    va_end(args);
}

void
generate_items(game_t* game)
{
    while (game->items->last_item < MAX_ITEMS) {
        int x = gen_number(1, MAP_WIDTH - 1);
        int y = gen_number(1, MAP_HEIGHT - 1);
        if (game->map[y][x].type == TL_FLOOR) {
            int item_seed = gen_number(1, 30);

            if (is_between(item_seed, 0, 10)) {
                add_item(game->items, item_init(IT_ROCK, x, y, "rock"));
            } else if (is_between(item_seed, 10, 25)) {
                add_item(game->items,
                         item_init(IT_WATER, x, y, "water bubble"));
            } else {
                add_item(game->items, item_init(IT_APPLE, x, y, "apple"));
            }
        }
    }
}
