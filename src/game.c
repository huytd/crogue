#include "rogue.h"
#include <string.h>

game_t* game_init() {
	game_t* game = (game_t*)malloc(sizeof(game_t));
	game->map = tile_map_init();
	game->player = player_init();
	game->messages_count = 0;
	memset(game->messages, 0, MAX_MESSAGES);
	return game;
}

void game_draw(game_t* game) {
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			draw_tile(x, y, game->map[y][x]);
		}
	}

	draw_player(game->player);
	draw_game_messages(game->messages, game->messages_count);
}

void game_input(game_t* game, char key) {
	switch (key) {
		case 'h': case 'j': case 'k': case 'l':
		case 'y': case 'n': case 'b': case 'u':
			player_try_move(game->player, game->map, key);
			break;
		default:
			game_message(game, "Sorry. '%c' is not a valid key!\n", key);
	}
}

void game_message(game_t* game, const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	vsnprintf(game->messages[game->messages_count].buf, MESSAGE_SIZE, fmt, args);
	game->messages_count++;
	// Probably not good, but for now, let's just limit the message
	// list to just 1024. We'll see.
	if (game->messages_count > MAX_MESSAGES)
		game->messages_count = 0;
	va_end(args);
}
