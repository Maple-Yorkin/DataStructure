#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define Maxsize 10

typedef struct Linknode
{
    int data;
    struct Linknode *next;
} Linknode, *LiStack;

// 创建、销毁、增删改查、获取长度
int IsEmpty(LiStack stack)
{
    if (stack == NULL)
        return true;
    return false;
}
int GetTop(LiStack stack)
{
    if (IsEmpty(stack) == true)
        return -1;
    return stack->data;
}
int Pop(LiStack *stack)
{
    if (IsEmpty(*stack) == true)
    {
        return -1;
    }
    int temp = GetTop(*stack);
    *stack = (*stack)->next;
    return temp;
}

void InitLiStack(LiStack *stack)
{
    *stack = NULL;
}

int Push(LiStack *stack, int e)
{
    Linknode *p = (Linknode *)malloc(sizeof(Linknode));
    if (p == NULL)
    {
        // 分配内存失败
        return 0; // 返回 0 表示推入失败
    }
    p->data = e;
    p->next = NULL;
    if (IsEmpty(*stack))
    {
        *stack = p;
    }
    else
    {
        p->next = *stack;
        *stack = p;
    }
    return 1;
}

int e = 2;
LiStack stack;

int main()
{

    InitLiStack(&stack);
    Push(&stack, e);
    printf("当前栈顶为：%d", GetTop(stack));
    Push(&stack, 4);
    Pop(&stack);
    printf("当前栈顶为：%d", GetTop(stack));
}