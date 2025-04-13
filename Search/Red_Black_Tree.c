#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MaxVertexNum 100

typedef struct RBnode
{                   // 红黑树的节点定义
    int key;        // 关键字的值
    RBnode *parent; // 父节点指针，找父节点的过程常被使用
    RBnode *lChild; // 左孩子指针
    RBnode *rChild; // 右孩子指针
    int color;      // 节点颜色，如用0/1表示黑/红，或C++中使用枚举类型enum表示颜色
} RBnode;