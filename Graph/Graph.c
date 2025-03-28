#include <stdio.h>
#include "../StackandQueue/SequenceQueue.c"
#include "../StackandQueue/SequenceStack.c"
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
void BFSTraverse(MGraph G)
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
void BFS(MGraph G, int v)
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

void DFSTraverse(MGraph G)
{
    for (int v = 0; v < G.vexnum; v++)
    {
        visited[v] = false;
    }
    for (int v = 0; v < G.vexnum; v++)
    {
        if (!visited[v])
            DFS(G, v);
    }
}
void DFS(MGraph G, int v)
{
    // 从顶点v触发，深度优先遍历图G
    visit(v);          // 访问顶点v
    visited[v] = true; // 设置访问标记
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
    {
        if (!visited[w]) // w为u的尚未访问的邻接顶点
        {
            DFS(G, w);
        }
    }
}
int d[Maxsize], path[Maxsize];
// 求顶点u到其他顶点的最短路径
void BFS_MIN_Distance(Graph G, int u)
{
    // d[i]表示从u到i节点的最短路径
    for (int i = 0; i < G.vexnum; i++)
    {
        d[i] = 0x3f3f3f3f; // 初始化路径长度
        path[i] = -1;      // 最短路径从哪个顶点过来
    }
    d[u] = 0;
    visited[u] = true;
    enqueue(&Q, u);
    while (!isEmpty(&Q)) // BFS算法主过程
    {
        dequeue(&Q); // 队头元素u出队
        for (int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
        {
            if (!visited[w]) // w为u的尚未访问的邻接顶点
            {
                d[w] = d[u] + 1;   // 路径长度+1
                path[w] = u;       // 最短路径应从u到w
                visited[w] = true; // 设已访问标记
                enqueue(&Q, w);    // 顶点w入队
            }
        }
    }
}
// Floyd算法核心代码
int A[Maxsize][Maxsize];
int Fpath[Maxsize][Maxsize];
int n;
// 根据图的信息初始化矩阵A和path
void Floyd()
{
    for (int k = 0; k < n; k++) // 若以Vk作为中转点
    {
        for (int i = 0; i < n; i++) // 每次遍历整个矩阵，i为行号，j为列号
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] > A[i][k] + A[k][j]) // 以Vk为中转点的路径更短
                {
                    A[i][j] = A[i][k] + A[k][j]; // 更新最短路径长度
                    Fpath[i][j] = k;             // 中转点
                }
            }
        }
    }
}
// 拓扑排序
typedef struct ArcNode // 边表节点
{
    int adjvex;              // 该弧所指向的顶点的位置
    struct ArcNode *nextarc; // 指向下一条弧的指针
    // InfoType info; //网的边权值
} ArcNode;
typedef struct VNode // 顶点表节点
{
    VertexType data;   // 顶点信息
    ArcNode *firstarc; // 指向第一条依附该节点的弧的指针
} VNode, AdjList[Maxsize];
typedef struct
{
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 图的顶点数和弧数
} VGraph;               // VGraph是以邻接表存储的图类型
SqStack S;              // 用来保存当前度为0的顶点，也可以用队列、数组等来进行代替
int indegree[Maxsize];  // 用于记录每一个节点当前的入度
int print[Maxsize];     // 用于记录得到的拓扑排序序列
int v;
int TypologicalSort(VGraph G)
{
    InitStack(S); // 初始化栈，存储入度为0的顶点
    for (int i = 0; i < G.vexnum; i++)
    {
        if (indegree[i] == 0)
            push(S, i);      // 将所有入度为0的顶点进栈
        int count = 0;       // 计数，记录当前已经输出的顶点数
        while (!isEmpty(&S)) // 栈不空，则存在入度为0的顶点
        {
            Pop(&S, i);         // 栈顶元素出栈
            print[count++] = i; // 输出顶点i
            for (ArcNode *p = G.vertices[i].firstarc; p; p = p->nextarc)

            {
                // 将所有i指向的顶点的入度减一，并且将入度减为0的顶点压入栈s
                v = p->adjvex;
                if (!(--indegree[v]))
                {
                    Push(&S, v); // 入度为0则入栈
                }
            }
        }
        if (count < G.vexnum)
        {
            return false; // 排序失败，有向图中有回路
        }
        else
        {
            return true; // 拓扑排序成功
        }
    }
}