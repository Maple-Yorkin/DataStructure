#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MaxSize 100

int UFSets[MaxSize];

void Initial(int S[])
{
    for (int i = 0; i < MaxSize; i++)
        S[i] = -1;
}

// //Find查，找x所属集合，返回x所属根节点
// int Find(int S[], int x)
// {
//     while(S[x]>=0)//循环查找x的根
//         x = S[x];
//     return x; //根的S[]小于0
// }

// //Union并，将两个集合合并为一个
// void Union(int S[], int Root1, int Root2)
// {
//     //要求Root1和Root2不是同一个集合
//     if(Root1==Root2)
//         return;
//         //将根Root2连接到另一个根Root1下面
//     S[Root2] = Root1;
// }

// 采取压缩路径优化Find函数
//  Find查，找x所属集合，找到x所属树的根节点，再进行压缩路径
int Find(int S[], int x)
{
    int root = x;
    while (S[root] >= 0) // 循环找根
        root = S[root];
    while (x != root)
    {                 // 压缩路径
        int t = S[x]; // t指向x的父节点
        S[x] = root;  // x直接挂到根节点下
        x = t;
    }
    return root; // 返回根节点编号
}

// Union并，将两个集合合并为一个，采取小树合并到大树的策略
// 用根节点的绝对值表示结点总数，在使用合并操作的时候将小树合并到大树
void Union(int S[], int Root1, int Root2)
{
    // 要求Root1与Root2是不同的集合
    if (Root1 == Root2)
        return;
    if (S[Root2] > S[Root1]) // 看谁结点数更少
    {
        S[Root1] += S[Root2]; // 累加结点总数
        S[Root2] = Root1;     // 小树合并到大树
    }
    else
    {
        S[Root2] += S[Root1]; // 累加结点总数
        S[Root1] = Root2;     // 小树合并到大树
    }
}