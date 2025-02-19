#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define Maxsize 10
typedef struct
{
    int data[Maxsize];
    int front, rear; // 队头指针和队尾指针
} SqQueue;

void initQueue(SqQueue *q)
{
    q->front = q->rear = 0;
}

int isEmpty(SqQueue *q)
{
    return q->front == q->rear;
}

int enqueue(SqQueue *q, int e)
{
    if ((q->rear + 1) % Maxsize == q->front)
    {
        return false;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % Maxsize;
    return true;
}

int dequeue(SqQueue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    int temp = q->data[q->front];
    q->front = (q->front + 1) % Maxsize;
    return temp;
}