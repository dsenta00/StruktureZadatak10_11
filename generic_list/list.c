#include "list.h"
#include <stdlib.h>
#include <string.h>

List *list_create(const char *name)
{
    List *list = malloc(sizeof(List));

    if (!list)
    {
        perror("List not allocated!\r\n");
        return NULL;
    }

    strcpy(list->name, name);
    list->count = 0;
    list->head.next = NULL;
    list->last = &list->head;

    return list;
}

void *list_first(List *list)
{
    return listNode_getDataFromNode(list->head.next);
}

int list_append(List *list, void *data)
{
    ListNodeP node = listNode_getNodeFromData(data);

    if (!node)
    {
        printf("Cannot insert NULL data!\r\n");
        return EXIT_FAILURE;
    }

    listNode_insertAfter(list->last, node);
    list->last = node;
    list->count++;

    return EXIT_SUCCESS;
}

int list_prepend(List *list, void *data)
{
    ListNodeP node = listNode_getNodeFromData(data);

    if (!node)
    {
        printf("Cannot insert NULL data!\r\n");
        return EXIT_FAILURE;
    }

    listNode_insertAfter(&list->head, node);

    if (list->count == 0)
    {
        list->last = node;
    }

    list->count++;

    return EXIT_SUCCESS;
}

int list_deleteFirst(List *list)
{
    if (list_isEmpty(list))
    {
        return EXIT_SUCCESS;
    }

    listNode_deleteAfter(&list->head);
    list->count--;

    if (list->count == 0)
    {
        list->last = &list->head;
    }

    return EXIT_SUCCESS;
}

int list_deleteLast(List *list)
{
    ListNodeP node = NULL;

    if (list_isEmpty(list))
    {
        return EXIT_SUCCESS;
    }

    for (node = &list->head;
         node->next != list->last;
         node = node->next)
        ;

    listNode_deleteAfter(node);
    list->last = node;
    list->count--;

    return EXIT_SUCCESS;
}

bool list_isEmpty(List *list)
{
    if (!list)
    {
        return true;
    }

    return list->count == 0;
}

int list_clear(List *list)
{
    while (!list_isEmpty(list))
    {
        list_deleteFirst(list);
    }

    return EXIT_SUCCESS;
}

int list_delete(List *list)
{
    if (!list)
    {
        return EXIT_SUCCESS;
    }

    list_clear(list);
    free(list);

    return EXIT_SUCCESS;
}