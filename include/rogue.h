#ifndef ROGUE_H
#define ROGUE_H

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tile.h"
#include "game.h"
#include "graphics.h"

#define OFFSET_TILES 	0
#define OFFSET_ENTITY 	1

static char GLYPH_MAP[] = {
	/* OFFSET_TILES  = 0 */
	'#', 	/* TL_WALL   */
	'.', 	/* TL_FLOOR  */
	',', 	/* TL_GRASS  */
	/* OFFSET_ENTITY = 2 */
	'@',    /* ET_PLAYER */
	'g',    /* ET_GLOBIN */
	'd',    /* ET_DOG    */
	'o',    /* ET_ORC    */
};

#define MAP_WIDTH 80
#define MAP_HEIGHT 25

#define MAX_ENTITIES 50

#endif
