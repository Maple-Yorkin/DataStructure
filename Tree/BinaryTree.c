#include <stdio.h>
#include <stdlib.h>
#include "../StackandQueue/LinkedQueue.c"
#define true 1
#define false 0
#define MaxSize 100
typedef struct TreeNode
{
    int value;
    int isEmpty
} TreeNode;
TreeNode t[MaxSize];

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void visit(BiTree T)
{
    printf("%d", &T->data);
}
// 先序遍历
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T); // 访问结点的函数，如打印
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
// 中序遍历
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
// 后序遍历
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

// 层序遍历
void LevelOrder(BiTree T)
{
    LinkQueue Q; // 辅助队列
    initQueue(&Q);
    BiTree p;
    EnQueue(Q, T);
    while (!IsEmpty(Q))
    {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild != NULL)
        {
            EnQueue(Q, p->lchild);
        }
        if (p->rchild != NULL)
        {
            EnQueue(Q, p->rchild);
        }
    }
}
int main()
{
    for (int i = 0; i < MaxSize; i++)
    {
        t[i].isEmpty = true;
    }
}
