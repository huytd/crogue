#ifndef GAME_H
#define GAME_H

#include "rogue.h"

typedef struct {
	tile_t** map;
} game_t;

game_t* game_init();
void game_draw(game_t* game);

#endif
