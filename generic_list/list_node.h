#pragma once
#include <stdio.h>

struct _listNode;
typedef struct _listNode *ListNodeP;
typedef struct _listNode
{
    ListNodeP next;
} ListNode;

void *listNode_allocate(size_t dataSize);
void *listNode_getDataFromNode(ListNodeP node);
void *listNode_nextData(void *data);
ListNodeP listNode_getNodeFromData(void *data);
int listNode_insertAfter(ListNodeP postion, ListNodeP node);
int listNode_deleteAfter(ListNodeP position);