#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "game.h"
#include "rogue.h"

static int SCREEN_HEIGHT = MAP_HEIGHT;
static int SCREEN_WIDTH  = MAP_WIDTH;

#define BORDER_SIZE         1

#define STYLE_OFFSET_TILE   100
#define STYLE_OFFSET_ENTITY 200
#define STYLE_OFFSET_ITEM   300

#define GLYPH_OFFSET_TILE   0
#define GLYPH_OFFSET_ENTITY 5
#define GLYPH_OFFSET_ITEM   9

#define STYLE_UNEXPLORED    1
#define STYLE_EXPLORED      2
#define GLYPH_UNEXPLORED    "░"

#define COLOR_DARK_GRAY     240
#define COLOR_LIGHT_GRAY    245
#define COLOR_DEFAULT       -1

static char* GLYPH_MAP[] = {
    /* GLYPH_OFFSET_TILE   = 0 */
    "♣",  /* TL_WALL  */
    ".",  /* TL_FLOOR */
    "\"", /* TL_GRASS */
    "~",  /* TL_WATER */
    "⌓",  /* TL_ROCK  */
    /* GLYPH_OFFSET_ENTITY = 5 */
    "@", /* ET_PLAYER */
    "b", /* ET_BUG    */
    "s", /* ET_SNAKE  */
    "m", /* ET_MICE   */
    "w", /* ET_WOLF   */
    "T", /* ET_TIGER  */
    "B", /* ET_BEAR   */
    /* GLYPH_OFFSET_ITEM   = 9 */
    "a", /* IT_APPLE  */
    "}", /* IT_BANANA */
    "%", /* IT_CORPSE */
};

void
graphics_init();

void
graphics_destroy();

void
draw_tile(int x, int y, tile_t t);

void
draw_entity(int x, int y, entity_type_e e);

void
draw_gui();

void
draw_game_messages(message_t messages[], int last_message);

#endif
