#include "list_node.h"
#include <stdlib.h>
#include <string.h>

void *listNode_allocate(size_t dataSize) {
    ListNodeP node = NULL;
    void *data = NULL;

    if (dataSize == 0) {
        printf("Data size cannot be null!\r\n");
        return NULL;
    }

    node = malloc(sizeof(ListNode) + dataSize);

    if (!node) {
        perror("List node failed to allocate!\r\n");
        return NULL;
    }

    node->next = NULL;
    data = listNode_getDataFromNode(node);
    memset(data, 0, dataSize);

    return node;
}

void *listNode_getDataFromNode(ListNodeP node) {
    if (!node) {
        return NULL;
    }

    return node + 1;
}

void *listNode_nextData(void *data) {
    ListNodeP node = listNode_getNodeFromData(data);

    if (!node) {
        return NULL;
    }

    return listNode_getDataFromNode(node->next);
}

ListNodeP listNode_getNodeFromData(void *data) {
    ListNodeP node = data;
    
    if (!data) {
        return NULL;
    }

    return node - 1;
}

int listNode_insertAfter(ListNodeP postion, ListNodeP node) {
    node->next = postion->next;
    postion->next = node;

    return EXIT_SUCCESS;
}

int listNode_deleteAfter(ListNodeP position) {
    ListNodeP toDelete = NULL;
    
    if (!position) {
        return EXIT_SUCCESS;
    }
    
    toDelete = position->next;

    if (!toDelete) {
        return EXIT_SUCCESS;
    }

    position->next = toDelete->next;
    free(toDelete);

    return EXIT_SUCCESS;
}