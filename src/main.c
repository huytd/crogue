#include "rogue.h"
#include "term.h"

int
main()
{
    srand(time(NULL));
    term_graphics_init();

    game_t* game = game_init();

    while (true) {
        draw_game(game);
        draw_gui();

        int key = getch();
        if (key == 'q')
            break;
        if (key == 'r')
            game->map = tile_map_init();
        game_input(game, key);
    }

    term_graphics_destroy();
    return 0;
}
