#ifndef PLAYER_H
#define PLAYER_H

#include "rogue.h"

typedef struct
{
    int x;
    int y;
    item_list_t* inventory;
} player_t;

player_t*
player_init();

void
player_try_move(player_t* p, tile_t** map, char direction);

item_t*
player_try_pickup(player_t* p, item_list_t* list);

#endif
