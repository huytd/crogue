#ifndef GAME_H
#define GAME_H

#include "rogue.h"

typedef struct {
	tile_t** map;
	player_t* player;
} game_t;

game_t* game_init();
void game_draw(game_t* game);
void game_input(game_t* game, char key);

#endif
