#ifndef LIGHT_H
#define LIGHT_H

#include "tile.h"
#include "player.h"

#define LIGHT_RADIUS 6

void
calculate_light(tile_t** map, player_t* player);

#endif
