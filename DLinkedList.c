#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkedList;

int InitDLinkList(DLinkedList *L)
{
    *L = (DNode *)malloc(sizeof(DNode));
    if (*L == NULL)
        return false;
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return true;
}

int IsEmpty(DLinkedList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}

int InsertNextDNode(DNode *p, int e)
{
    if (p == NULL)
        return false;
    DNode *s = (DNode *)malloc(sizeof(DNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->prior = p;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    p->next = s;
    return true;
}

int DeleteNextDNode(DNode *p, int *e)
{
    if (p == NULL)
        return false;
    DNode *q = p->next;
    if (q == NULL)
        return false;
    *e = q->data;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

void DestroyList(DLinkedList *L)
{
    DNode *p = *L, *q = p->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
    *L = NULL;
}