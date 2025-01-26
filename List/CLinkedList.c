#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

int InitList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL)
        return false;
    (*L)->next = L;
    return true;
}

int empty(LinkList L)
{
    if (L->next == L)
        return true;
    else
        return false;
}