#ifndef ITEM_H
#define ITEM_H

typedef enum
{
    IT_APPLE  = 0,
    IT_BANANA = 1,
    IT_CORPSE = 2,
    IT_WATER  = 3,
    IT_ROCK   = 4
} item_type_e;

typedef struct
{
    item_type_e type;
    int x;
    int y;
    char* name;
} item_t;

typedef struct
{
    item_t** items;
    int last_item;
} item_list_t;

item_t*
item_init(item_type_e type, int x, int y, char* name);

item_list_t*
item_list_init();

void
add_item(item_list_t* list, item_t* item);

item_t*
remove_item(item_list_t* list, int index);

int
get_item_at(item_list_t* list, int x, int y);

item_t*
get_item(item_list_t* list, int index);

#endif
