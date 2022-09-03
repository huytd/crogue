#include "light.h"

void
calculate_light(tile_t** map, player_t* player)
{
    for (int y = player->y - LIGHT_RADIUS * 2; y < player->y + LIGHT_RADIUS * 2;
         y++) {
        for (int x = player->x - LIGHT_RADIUS * 2;
             x < player->x + LIGHT_RADIUS * 2;
             x++) {
            if (is_within_map(x, y)) {
                map[y][x].visible = false;
                if ((x - player->x) * (x - player->x) +
                      (y - player->y) * (y - player->y) <=
                    LIGHT_RADIUS * LIGHT_RADIUS) {
                    map[y][x].explored = true;
                    map[y][x].visible  = true;
                }
            }
        }
    }
}
