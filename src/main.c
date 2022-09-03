#include "rogue.h"

int
main()
{
    srand(time(NULL));
    graphics_init();

    game_t* game = game_init();

    while (true) {
        game_draw(game);
        draw_gui();

        int key = getch();
        if (key == 'q')
            break;
        if (key == 'r')
            game->map = tile_map_init();
        game_input(game, key);
    }

    graphics_destroy();
    return 0;
}
