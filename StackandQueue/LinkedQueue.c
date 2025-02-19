#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define Maxsize 10

typedef struct Linknode
{
    int data;
    struct Linknode *next;
} Linknode, *LiQueue;

typedef struct
{
    Linknode *front, *rear;
} LinkQueue;

void initQueue(LinkQueue *q)
{
    q->front = q->rear = (Linknode *)malloc(sizeof(Linknode));
    q->front->next = NULL;
}
int isEmpty(LinkQueue *q)
{
    return q->front == q->rear;
}
// 带头结点
void enqueue(LinkQueue *q, int e)
{
    Linknode *p = (Linknode *)malloc(sizeof(Linknode));
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

void dequeue(LinkQueue *q)
{
    if (isEmpty(q))
    {
        return;
    }
    Linknode *p = q->front->next;
    q->front->next = p->next;
    if (q->rear == p)
    {
        q->rear = q->front;
    }
    free(p);
}
