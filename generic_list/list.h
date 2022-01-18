#pragma once
#include "list_node.h"
#include <stdbool.h>

#define MAX_LIST_NAME (128)
#define list_foreach(__p, __list) for (__p = list_first(__list); __p != NULL; __p = listNode_nextData(__p))

typedef struct _list
{
    char name[MAX_LIST_NAME];
    size_t count;
    ListNode head;
    ListNodeP last;
} List;

List *list_create(const char *name);
void *list_first(List *list);
int list_append(List *list, void *data);
int list_prepend(List *list, void *data);
int list_deleteFirst(List *list);
int list_deleteLast(List *list);
bool list_isEmpty(List *list);
int list_clear(List *list);
int list_delete(List *list);