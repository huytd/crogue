#include "rogue.h"

tile_t make_tile(tile_type_e type) {
	tile_t tile;
	tile.type = type;
	tile.explored = false;
	tile.visible = false;
	return tile;
}

tile_t** tile_map_init() {
	tile_t** map = calloc(MAP_HEIGHT, sizeof(tile_t*));
	for (int y = 0; y < MAP_HEIGHT; y++) {
		map[y] = calloc(MAP_WIDTH, sizeof(tile_t));
		for (int x = 0; x < MAP_WIDTH; x++) {
			map[y][x] = make_tile(TL_FLOOR);
			// mockup room logic
			int dice = rand() % 100 + 1;
			if (dice < 50 && dice > 20) {
				map[y][x].type = TL_WALL;
			}
			if (dice > 5 && dice <= 20) {
				map[y][x].type = TL_GRASS;
			}
			if (dice > 1 && dice <= 5) {
				map[y][x].type = TL_ROCK;
			}
			if (dice <= 1) {
				map[y][x].type = TL_WATER;
			}
		}
	}
	return map;
}
