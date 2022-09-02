#include "rogue.h"

game_t* game_init() {
	game_t* game = (game_t*)malloc(sizeof(game_t));
	game->map = tile_map_init();
	game->player = player_init();
	return game;
}

void game_draw(game_t* game) {
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			draw_tile(x, y, game->map[y][x]);
		}
	}

	draw_player(game->player);
}

void game_input(game_t* game, char key) {
	switch (key) {
		case 'h': case 'j': case 'k': case 'l':
		case 'y': case 'n': case 'b': case 'u':
			player_try_move(game->player, game->map, key);
			break;
	}
}
