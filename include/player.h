#ifndef PLAYER_H
#define PLAYER_H

#include "rogue.h"

typedef struct {
	int x;
	int y;
} player_t;

player_t* player_init();
void draw_player(player_t* p);
void player_try_move(player_t* p, tile_t** map, char direction);

#endif
