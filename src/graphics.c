#include "rogue.h"
#include "util.h"
#include <locale.h>

static WINDOW* map_win;
static WINDOW* msg_border_win;
static WINDOW* msg_content_win;
static WINDOW* ctl_win;

static int MSG_CAPACITY = 0;

void
graphics_init()
{
    setlocale(LC_ALL, "");

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(false);
    use_default_colors();
    start_color();

    init_pair(STYLE_UNEXPLORED, COLOR_DARK_GRAY, COLOR_DEFAULT);
    init_pair(STYLE_EXPLORED, COLOR_LIGHT_GRAY, COLOR_DEFAULT);
    init_pair(STYLE_OFFSET_TILE + TL_WALL, COLOR_GREEN, COLOR_DEFAULT);
    init_pair(STYLE_OFFSET_TILE + TL_FLOOR, COLOR_YELLOW, COLOR_DEFAULT);
    init_pair(STYLE_OFFSET_TILE + TL_GRASS, COLOR_GREEN, COLOR_DEFAULT);
    init_pair(STYLE_OFFSET_TILE + TL_WATER, COLOR_BLUE, COLOR_DEFAULT);
    init_pair(STYLE_OFFSET_TILE + TL_ROCK, COLOR_WHITE, COLOR_DEFAULT);
    init_pair(STYLE_OFFSET_ENTITY + ET_PLAYER, COLOR_BLACK, COLOR_YELLOW);

    getmaxyx(stdscr, SCREEN_HEIGHT, SCREEN_WIDTH);

    int map_win_height = MAP_HEIGHT + 2 * BORDER_SIZE;
    int map_win_width  = MAP_WIDTH + 2 * BORDER_SIZE;
    map_win            = newwin(map_win_height, map_win_width, 0, 0);
    msg_border_win =
      newwin(SCREEN_HEIGHT - map_win_height, map_win_width, map_win_height, 0);
    msg_content_win = newwin(SCREEN_HEIGHT - map_win_height - 2,
                             map_win_width - 2,
                             map_win_height + 1,
                             1);
    ctl_win =
      newwin(SCREEN_HEIGHT, SCREEN_WIDTH - map_win_width, 0, map_win_width);

    box(map_win, 0, 0);
    box(msg_border_win, 0, 0);
    box(ctl_win, 0, 0);

    MSG_CAPACITY = getmaxy(msg_content_win);

    refresh();
}

void
graphics_destroy()
{
    endwin();
}

void
draw_tile(int x, int y, tile_t t)
{
    if (!t.explored) {
        wattrset(map_win, COLOR_PAIR(STYLE_UNEXPLORED));
        mvwaddstr(map_win, y + BORDER_SIZE, x + BORDER_SIZE, GLYPH_UNEXPLORED);
    } else {
        wattrset(map_win, COLOR_PAIR(STYLE_EXPLORED));
        if (t.visible) {
            wattrset(map_win, COLOR_PAIR(STYLE_OFFSET_TILE + t.type));
        }
        mvwaddstr(map_win,
                  y + BORDER_SIZE,
                  x + BORDER_SIZE,
                  GLYPH_MAP[GLYPH_OFFSET_TILE + t.type]);
    }
}

void
draw_entity(int x, int y, entity_type_e e)
{
    wattron(map_win, COLOR_PAIR(STYLE_OFFSET_ENTITY + e));
    mvwaddstr(map_win,
              y + BORDER_SIZE,
              x + BORDER_SIZE,
              GLYPH_MAP[GLYPH_OFFSET_ENTITY + e]);
    wattroff(map_win, COLOR_PAIR(STYLE_OFFSET_ENTITY + e));
}

void
draw_gui()
{
    wrefresh(map_win);
    wrefresh(msg_border_win);
    wrefresh(msg_content_win);
    wrefresh(ctl_win);
}

void
draw_game_messages(message_t messages[], int last_message)
{
    wmove(msg_content_win, 0, 0);
    int start = max(0, last_message - MSG_CAPACITY);
    for (int i = start; i < last_message; i++) {
        if (i == last_message - 1) {
            wattron(msg_content_win, A_BOLD);
        } else {
            wattron(msg_content_win, A_NORMAL | A_DIM);
        }
        wprintw(msg_content_win, messages[i].buf);
        wattroff(msg_content_win, A_NORMAL | A_DIM | A_BOLD);
    }
}
