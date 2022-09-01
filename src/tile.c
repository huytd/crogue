#include "rogue.h"

Tile make_tile(TileType type) {
	Tile tile;
	tile.type = type;
	tile.explored = false;
	tile.visible = false;
	return tile;
}

Tile** tile_map_init() {
	Tile** map = calloc(MAP_HEIGHT, sizeof(Tile*));
	for (int y = 0; y < MAP_HEIGHT; y++) {
		map[y] = calloc(MAP_WIDTH, sizeof(Tile));
		for (int x = 0; x < MAP_WIDTH; x++) {
			map[y][x] = make_tile(TL_WALL);
			// mockup room logic
			int dice = rand() % 100 + 1;
			if (dice < 80 && dice > 10) {
				map[y][x].type = TL_FLOOR;
			}
			if (dice <= 10) {
				map[y][x].type = TL_GRASS;
			}
		}
	}
	return map;
}
