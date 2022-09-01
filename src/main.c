#include "rogue.h"

int main() {
	srand(time(NULL));
	graphics_init();

	game_t* game = game_init();

	while (true) {
		game_draw(game);

		int key = getch();
		if (key == 'q') break;
		if (key == 'r') game->map = tile_map_init();
	}

	graphics_destroy();
	return 0;
}

