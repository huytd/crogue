#include "rogue.h"
#include <locale.h>

void graphics_init() {
	setlocale(LC_ALL, "");

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(false);
	start_color();

	init_pair(STYLE_OFFSET_TILE + TL_WALL, 	COLOR_GREEN,  COLOR_BLACK);
	init_pair(STYLE_OFFSET_TILE + TL_FLOOR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(STYLE_OFFSET_TILE + TL_GRASS, COLOR_GREEN,  COLOR_BLACK);
	init_pair(STYLE_OFFSET_TILE + TL_WATER, COLOR_BLUE,   COLOR_BLACK);
	init_pair(STYLE_OFFSET_TILE + TL_ROCK, 	COLOR_WHITE,  COLOR_BLACK);

	init_pair(STYLE_OFFSET_ENTITY + ET_PLAYER, COLOR_BLACK, COLOR_YELLOW);

	getmaxyx(stdscr, SCREEN_HEIGHT, SCREEN_WIDTH);
}

void graphics_destroy() {
	endwin();
}

void draw_tile(int x, int y, tile_t t) {
	attron(COLOR_PAIR(STYLE_OFFSET_TILE + t.type));
	mvaddstr(y, x, GLYPH_MAP[GLYPH_OFFSET_TILE + t.type]);
	attroff(COLOR_PAIR(STYLE_OFFSET_TILE + t.type));
}

void draw_entity(int x, int y, entity_type_e e) {
	attron(COLOR_PAIR(STYLE_OFFSET_ENTITY + e));
	mvaddstr(y, x, GLYPH_MAP[GLYPH_OFFSET_ENTITY + e]);
	attroff(COLOR_PAIR(STYLE_OFFSET_ENTITY + e));
}
