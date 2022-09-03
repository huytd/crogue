#ifndef GAME_H
#define GAME_H

#include "rogue.h"

#define MESSAGE_SIZE 256
#define MAX_MESSAGES 1024

typedef struct
{
    char buf[MESSAGE_SIZE];
} message_t;

typedef struct
{
    tile_t** map;
    player_t* player;
    message_t messages[MAX_MESSAGES];
    int messages_count;
} game_t;

game_t*
game_init();

void
game_draw(game_t* game);

void
game_input(game_t* game, char key);

void
game_message(game_t* game, const char* fmt, ...);

#endif
