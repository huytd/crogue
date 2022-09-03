#include "rogue.h"

player_t*
player_init()
{
    player_t* player = (player_t*)malloc(sizeof(player_t));
    player->x        = MAP_WIDTH / 2;
    player->y        = MAP_HEIGHT / 2;
    return player;
}

void
draw_player(player_t* p)
{
    draw_entity(p->x, p->y, ET_PLAYER);
}

void
player_try_move(player_t* p, tile_t** map, char direction)
{
    int dx = 0;
    int dy = 0;
    if (direction == 'h') {
        dx = -1;
        dy = 0;
    }
    if (direction == 'l') {
        dx = 1;
        dy = 0;
    }
    if (direction == 'j') {
        dx = 0;
        dy = 1;
    }
    if (direction == 'k') {
        dx = 0;
        dy = -1;
    }
    if (direction == 'y') {
        dx = -1;
        dy = -1;
    }
    if (direction == 'n') {
        dx = 1;
        dy = 1;
    }
    if (direction == 'b') {
        dx = -1;
        dy = 1;
    }
    if (direction == 'u') {
        dx = 1;
        dy = -1;
    }
    int nx = p->x + dx;
    int ny = p->y + dy;
    if (is_within_map(nx, ny) && map[ny][nx].type != TL_WALL &&
        map[ny][nx].type != TL_ROCK) {
        p->x = nx;
        p->y = ny;
    }
}
