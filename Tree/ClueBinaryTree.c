#include <stdio.h>
#include <stdlib.h>
#include "../StackandQueue/LinkedQueue.c"
#define true 1
#define false 0
#define MaxSize 100
// 二叉树结点（链式存储）
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// 线索二叉树结点
typedef struct ThreadNode
{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;
// 辅助全局变量pre，用来指向当前访问结点的前驱
ThreadNode *pre = NULL;

void InThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

void visit(ThreadNode *q)
{
    if (q->lchild == NULL) // 如果左子树为空则建立前驱线索
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = q; // 建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}
// 中序线索化
void CreateInThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        InThread(T);
        if (pre->rchild == NULL)
        {
            pre->rtag = 1;
        }
    }
}
void PreThread(ThreadTree T)
{
    if (T != NULL)
    {
        visit(T);
        if (T->ltag == 0) // 判断lchild是不是前驱线索，防止发生死循环
        {
            preThread(T->lchild);
        }
        PreThread(T->rchild);
    }
}

// 中序线索二叉树找中序后继
// 找到以P为根的子树中，第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p)
{
    while (p->ltag == 0)
    {
        p = p->lchild;
    }
    return p;
}
// 在中序线索二叉树中找到结点p的后继节点
ThreadNode *Nextnode(ThreadNode *p)
{
    // 右子树中最左下结点
    if (p->rtag == 0)
    {
        return Firstnode(p->rchild);
    }
    else
    {
        return p->rchild; // rtag==1直接返回后继线索
    }
}
// 对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void Inorder(ThreadNode *T)
{
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
        visit(p);
}

// 在中序线索二叉树找中序前驱
// 找到以P为根的子树中，最后一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p)
{
    // 循环找到最右下结点，不一定是叶子节点
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}
// 在中序线索二叉树中找到结点p的前驱节点
ThreadNode *Prenode(ThreadNode *p)
{
    // 左子树中最右下结点
    if (p->ltag == 0)
        return Lastnode(p->lchild);
    else
        return p->lchild;
    // ltag==1则直接返回前驱线索
}
// 对中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode *T)
{
    for (ThreadNode *p = Lastnode(T); p != NULL; p = Prenode(p))
    {
        visit(p);
    }
}
