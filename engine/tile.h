#ifndef TILE_H
#define TILE_H

#include "rogue.h"

typedef enum
{
    TL_WALL  = 0,
    TL_FLOOR = 1,
    TL_GRASS = 2,
} tile_type_e;

typedef struct
{
    tile_type_e type;
    bool explored;
    bool visible;
} tile_t;

tile_t
make_tile(tile_type_e type);

tile_t**
tile_map_init();

#endif
