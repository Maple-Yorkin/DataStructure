#include <stdio.h>
#include <stdlib.h>
#include "../StackandQueue/LinkedQueue.c"
#define true 1
#define false 0
#define MaxSize 100

// 双亲表示法
typedef struct
{ // 树的结点定义

    int data;   // 数据元素
    int parent; // 双亲位置域
} PTNode;

typedef struct
{                          // 树的类型定义
    PTNode nodes[Maxsize]; // 双亲表示
    int n;                 // 结点数

} PTree;

// 孩子表示法
// 保存各个孩子数组下标的结构体
struct CTNode
{
    int child;           // 孩子结点在数组中的位置
    struct CTNode *next; // 下一个孩子
};
// 实际存储数据的结构体
typedef struct
{
    int data;
    struct CTNode *firstChild; // 第一个孩子
} CTBox;
typedef struct
{
    CTBox nodes[Maxsize];
    int n, r; // 结点数和根结点的位置
} CTree;

// 孩子兄弟表示法
typedef struct CSNode
{
    int data;                                // 数据域
    struct CSNode *firstchild, *nextsibling; // 第一个孩子和右兄弟指针
} CSNode, *CSTree;

// 下面的遍历代码由伪代码组成，实际实现的时候需要根据具体的存储结构进行设计
// // 先根遍历
// void PreOrder(TreeNode *R)
// {
//     if (R != NULL)
//     {
//         visit(R); // 访问根节点
//         while (R还有下一个子树T)
//             PreOrder(T); // 先根遍历下一棵子树
//     }
// }
// // 后根遍历
// void PostOrder(TreeNode *R)
// {
//     if(R!=NULL)
//     {
//         while(R还有下一个子树T)
//             PostOrder(T);
//         visit(R);
//     }
// }