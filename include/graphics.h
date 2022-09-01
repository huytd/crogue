#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "rogue.h"

void graphics_init();
void graphics_destroy();

void draw_tile(int x, int y, tile_t t);

#endif
