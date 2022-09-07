#include "rogue.h"

player_t*
player_init()
{
    player_t* player  = (player_t*)malloc(sizeof(player_t));
    player->x         = MAP_WIDTH / 2;
    player->y         = MAP_HEIGHT / 2;
    player->inventory = item_list_init();
    return player;
}

void
player_try_move(player_t* p, tile_t** map, char direction)
{
    int dx = 0;
    int dy = 0;
    if (direction == 'h') {
        dx = -1;
        dy = 0;
    }
    if (direction == 'l') {
        dx = 1;
        dy = 0;
    }
    if (direction == 'j') {
        dx = 0;
        dy = 1;
    }
    if (direction == 'k') {
        dx = 0;
        dy = -1;
    }
    if (direction == 'y') {
        dx = -1;
        dy = -1;
    }
    if (direction == 'n') {
        dx = 1;
        dy = 1;
    }
    if (direction == 'b') {
        dx = -1;
        dy = 1;
    }
    if (direction == 'u') {
        dx = 1;
        dy = -1;
    }
    int nx = p->x + dx;
    int ny = p->y + dy;
    if (is_within_map(nx, ny) && map[ny][nx].type != TL_WALL) {
        p->x = nx;
        p->y = ny;
    }
}

item_t*
player_try_pickup(player_t* p, item_list_t* list)
{
    int item_index = get_item_at(list, p->x, p->y);
    if (item_index != -1) {
        item_t* item = remove_item(list, item_index);
        add_item(p->inventory, item);
        return item;
    }
    return NULL;
}
