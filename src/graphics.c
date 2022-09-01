#include "rogue.h"

void graphics_init() {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(false);
	start_color();

	init_pair(TL_WALL, COLOR_WHITE, COLOR_WHITE);
	init_pair(TL_FLOOR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(TL_GRASS, COLOR_GREEN, COLOR_BLACK);
}

void graphics_destroy() {
	endwin();
}

void draw_tile(int x, int y, tile_t t) {
	attron(COLOR_PAIR(t.type));
	mvaddch(y, x, GLYPH_MAP[OFFSET_TILES + t.type]);
	attroff(COLOR_PAIR(t.type));
}
