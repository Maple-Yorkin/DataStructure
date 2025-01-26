#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define Maxsize 10

typedef struct
{
    int data[Maxsize];
    int top;
} SqStack;
// shared stack
typedef struct
{
    int data[Maxsize];
    int top0;
    int top1;
} ShStack;

int StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}
int Push(SqStack *S, int x)
{
    if (S->top == Maxsize - 1)
        return false;
    S->top++;
    S->data[S->top] = x;
    return true;
}
int Pop(SqStack *S, int *x)
{
    if (S->top == -1)
        return false;
    *x = S->data[S->top];
    S->top--;
    return true;
}
int GetTop(SqStack S, int *x)
{
    if (S.top == -1)
        return false;
    *x = S.data[S.top];
    return true;
}
void initStack(SqStack *S)
{
    S->top = -1;
}

void initShStack(ShStack *S)
{
    S->top0 = -1;
    S->top1 = Maxsize;
}