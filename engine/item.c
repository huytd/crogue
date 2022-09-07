#include "rogue.h"

item_t*
item_init(item_type_e type, int x, int y, char* name)
{
    item_t* item = (item_t*)malloc(sizeof(item_t));
    item->type   = type;
    item->x      = x;
    item->y      = y;
    item->name   = name;
    return item;
}

item_list_t*
item_list_init()
{
    item_list_t* list = (item_list_t*)malloc(sizeof(item_list_t));
    list->items       = calloc(MAX_ITEMS, sizeof(item_t));
    list->last_item   = -1;
    return list;
}

void
add_item(item_list_t* list, item_t* item)
{
    if (list->last_item < MAX_ITEMS) {
        list->last_item++;
        list->items[list->last_item] = item;
    }
}

item_t*
remove_item(item_list_t* list, int index)
{
    if (index <= list->last_item) {
        item_t* item                 = list->items[index];
        item_t* last                 = list->items[list->last_item];
        list->items[index]           = last;
        list->items[list->last_item] = NULL;
        list->last_item--;
        return item;
    }
    return NULL;
}

int
get_item_at(item_list_t* list, int x, int y)
{
    for (int i = 0; i <= list->last_item; i++) {
        if (list->items[i]->x == x && list->items[i]->y == y) {
            return i;
        }
    }
    return -1;
}

item_t*
get_item(item_list_t* list, int index)
{
    if (index <= list->last_item) {
        return list->items[index];
    }
    return NULL;
}
