#ifndef ROGUE_H
#define ROGUE_H

#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH    80
#define MAP_HEIGHT   24

#define MAX_ENTITIES 50

typedef enum
{
    ET_PLAYER = 0,
    ET_BUG    = 1,
    ET_SNAKE  = 2,
    ET_BAT    = 3,
    ET_MICE   = 4,
    ET_WOLF   = 5,
    ET_TIGER  = 6,
    ET_BEAR   = 7,
} entity_type_e;

#include "tile.h"
#include "item.h"
#include "player.h"
#include "light.h"
#include "game.h"

#endif
