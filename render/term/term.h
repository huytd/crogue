#ifndef TERM_GRAPHICS_H
#define TERM_GRAPHICS_H

#include "rogue.h"

static int SCREEN_HEIGHT = MAP_HEIGHT;
static int SCREEN_WIDTH  = MAP_WIDTH;

#define BORDER_SIZE         1

#define STYLE_OFFSET_TILE   10
#define STYLE_OFFSET_ENTITY 30
#define STYLE_OFFSET_ITEM   60

#define GLYPH_OFFSET_TILE   0
#define GLYPH_OFFSET_ENTITY 3
#define GLYPH_OFFSET_ITEM   10

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
    /* GLYPH_OFFSET_ENTITY = 3 */
    "@", /* ET_PLAYER */
    "b", /* ET_BUG    */
    "s", /* ET_SNAKE  */
    "m", /* ET_MICE   */
    "w", /* ET_WOLF   */
    "T", /* ET_TIGER  */
    "B", /* ET_BEAR   */
    /* GLYPH_OFFSET_ITEM   = 10 */
    "a", /* IT_APPLE  */
    "}", /* IT_BANANA */
    "%", /* IT_CORPSE */
    "~", /* IT_WATER  */
    "⌓", /* IT_ROCK   */
};

void
term_graphics_init();

void
term_graphics_destroy();

void
draw_tile(int x, int y, tile_t t);

void
draw_entity(int x, int y, entity_type_e e);

void
draw_item(item_t* item, tile_t** map);

void
draw_gui();

void
draw_game_messages(message_t messages[], int last_message);

void
draw_game(game_t* game);

#endif
