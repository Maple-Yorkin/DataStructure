#include <stdio.h>
#include "../StackandQueue/SequenceQueue.c"
#include <stdlib.h>
#define true 1
#define false 0
#define MaxVertexNum 100
#define INFINITY 0x3f3f3f3f // 宏定义常量无穷

typedef struct
{                                         // 顶点数目的最大值
    char Vex[MaxVertexNum];               // 顶点表，当然可以不是char而是一些其他更复杂的结构体
    int Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵，边表。边一般只有两种状态，因此可以用bool或枚举类型
    int vexnum, arcnum;                   // 图的当前顶点数和边数/弧数
} MGraph;

typedef char VertexType; // 顶点的数据类型
typedef int EdgeType;    // 带权图中边上权值的数据类型
typedef struct
{
    VertexType Vex[MaxVertexNum];              // 顶点
    EdgeType Edge[MaxVertexNum][MaxVertexNum]; // 边的权
    int vexnum, arcnum;                        // 图的当前顶点数和弧数
} WMGraph;
// 边/弧
typedef struct ArcNode
{
    int adjvex;           // 边/弧指向哪个结点
    struct ArcNode *next; // 指向下一条弧的指针
    // InfoType info; //边权值
} ArcNode;
// 顶点
typedef struct VNode
{
    VertexType data; // 顶点信息
    ArcNode *first;  // 第一条边
} VNode, AdjList[MaxVertexNum];
// 用邻接表存储的图
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

// BFS
int visited[MaxVertexNum]; // 访问标记
SqQueue Q;
// Graph，具体情况要具体定义，如采用邻接矩阵实现还是邻接表
typedef struct Graph
{
    int vexnum; // 节点数量
    /* data */
} Graph;
void BFSTraverse(Graph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false; // 将标记数组初始化
    }
    initQueue(&Q); // 初始化辅助队列
    for (int i = 0; i < G.vexnum; i++)
    {
        // 从0号顶点开始遍历
        if (!visited[i]) // 对每个连通分量调用一次BFS
        {
            BFS(G, i); // 对没访问过的vi开始进行新一轮的BFS
        }
    }
}
void BFS(Graph G, int v)
{
    // 从顶点v出发，对图G进行广度优先搜索
    visit(v);          // 访问初始顶点v
    visited[v] = true; // 对即将访问的v做访问标记
    enqueue(&Q, v);    // 顶点v入队列Q
    while (!isEmpty(&Q))
    {
        dequeue(&Q); // 队头的顶点v出队列
        // 检测v所有邻接点
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
        {
            // w为v尚未访问的邻接顶点
            if (!visited[w])
            {
                visit(w);          // 对w进行访问
                visited[w] = true; // 对w做访问标记
                enqueue(&Q, w);    // 顶点w入队列
            }
        }
    }
}