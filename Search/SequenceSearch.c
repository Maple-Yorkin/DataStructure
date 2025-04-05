#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MaxVertexNum 100
typedef struct
{                 // 查找表的数据结构（以顺序表为例）
    int *elem;    // 动态数组基址
    int TableLen; // 表长
} SSTable;
// 顺序查找
int Search_Seq(SSTable ST, int key)
{
    int i;
    for (i = 0; i < ST.TableLen && ST.elem[i] != key; i++)
    {
        // 查找成功则返回元素下标，查找失败则返回-1
    }
    return i == ST.TableLen ? -1 : i;
}
// 二分，使用前需要先排序。以升序为例
int Binary_Search(SSTable L, int key)
{
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.elem[mid] == key)
            return mid;
        else if (L.elem[mid] > key)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return -1;
}
// 二叉排序树结点
typedef struct BSTNode
{
    int key; // 结点可以包含更复杂的信息，但是在查找中需要定义好排序的规则
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;
// 在二叉排序树中查找值为key的结点
BSTNode *BST_Loop_Search(BSTree T, int key)
{
    while (T != NULL && key != T->key) // 若树空或等于根节点值则结束循环
    {
        if (key < T->key)
            T = T->lchild; // 小于则在左子树上查找
        else
            T = T->rchild; // 大于则在柚子树上查找
    }
    return T;
}
// 在二叉排序树中查找值为key的结点（递归实现）
BSTNode *BST_Recursion_Search(BSTree T, int key)
{
    if (T == NULL)
        return NULL;
    if (key == T->key)
        return T;
    else if (key < T->key)
    {
        return BST_Recursion_Search(T->lchild, key);
    }
    else
    {
        return BST_Recursion_Search(T->rchild, key);
    }
}
// 二叉排序树的插入，插入关键字为k的新结点（递归实现）
int BST_Insert(BSTree T, int k)
{
    if (T == NULL) // 原树为空，新插入的节点为根节点
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1; // 插入成功
    }
    else if (k == T->key) // 如果存在相同关键字的结点则插入失败
        return 0;
    else if (k < T->key) // 进入左子树
    {
        return BST_Insert(T->lchild, k);
    }
    else // 进入右子树
    {
        return BST_Insert(T->rchild, k);
    }
}
