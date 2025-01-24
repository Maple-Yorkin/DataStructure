#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 函数声明
int IsEmpty(LinkList L);
int InitList(LinkList *L);
int ListInsert(LinkList *L, int i, int e);
int InsertNextNode(LNode *p, int e);
int InsertPriorNode(LNode *p, int e);
int ListDelete(LinkList *L, int i, int *e);
int DeleteNode(LNode *p);
LNode *GetElem(LinkList L, int i);
LNode *LocateElem(LinkList L, int e);
int Length(LinkList L);
LinkList List_TailInsert(LinkList *L);
LinkList List_HeadInsert(LinkList *L);
void printList(LinkList L);
// 判断单链表是否为空
int IsEmpty(LinkList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}
// 初始化单链表
int InitList(LinkList *L)
{
    // L = NULL; 若申请无头结点单链表则L=NULL
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L = NULL)
        return false;
    (*L)->next = NULL;
    return true;
}
// 按位序插入结点操作
int ListInsert(LinkList *L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p = GetElem(*L, i - 1); // 查找第i-1个结点
    return InsertNextNode(p, e);
}
// 后插操作：在p结点之后插入元素e
int InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) // 内存分配失败
        return false;
    s->data = e; // 用结点s保存数据元素e
    s->next = p->next;
    p->next = s; // 将结点s连接到p之后
    return true;
}
// 前插操作：在p结点之前插入元素e
int InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;       // 新结点s连接到p
    s->data = p->data; // 将p中元素复制到s中
    p->data = e;       // p中元素覆盖为e
    return true;
}
// 按位序删除结点操作
int ListDelete(LinkList *L, int i, int *e)
{
    if (i < 1)
        return false;
    LNode *p = GetElem(*L, i - 1); // 查找第i-1个结点
    // 如果找不到则返回false
    if (p == NULL)
        return false;
    // 如果找到了则删除第i个结点
    LNode *q = p->next; // 令q指向被删除结  点
    if (q == NULL)
        return false;
    *e = q->data;      // 用e返回元素的值
    p->next = q->next; // 将*q结点从链中断开
    free(q);           // 最后释放结点的空间
    return true;
}

int DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    LNode *q = p->next; // 令q指向被删除结点
    if (q == NULL)
        return false;
    p->data = q->data; // 用后继结点数据域替换当前结点数据域
    p->next = q->next; // 将*q结点从链中断开
    free(q);           // 最后释放结点的空间
    return true;
}

// 按位查找：返回第i个元素（带头结点）
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p = L;              // 指针p指向当前扫描到的结点
    int j = 0;                 // 当前p指向的是第几个结点
    p = L;                     // L指向头结点，头结点是第0个结点（不存数据）
    while (p != NULL && j < i) // 循环直到p指向第i个结点或p为空
    {
        p = p->next;
        j++;
    }
    return p;
}
// 按值查找：返回值为e的元素（带头结点）
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next; // p指向第一个结点并开始查找
    while (p != NULL && p->data != e)
        p = p->next;
    return p; // 查找成功返回结点指针，否则返回NULL
}
int Length(LinkList L)
{
    LNode *p = L->next; // p指向第一个结点
    int len = 0;        // 初始化长度为0
    while (p != NULL)   // 遍历整个链表
    {
        p = p->next;
        len++;
    }
    return len;
}
// 尾插法实现单链表的创建
LinkList List_TailInsert(LinkList *L)
{
    int x;
    *L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = *L; // r为表尾指针
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return *L;
}
// 头插法实现单链表的创建
LinkList List_HeadInsert(LinkList *L)
{
    int x;
    *L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    (*L)->next = NULL;
    LNode *s;        // 声明一个结点
    scanf("%d", &x); // 输入结点的值
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode)); // 创建一个新结点
        s->data = x;
        s->next = (*L)->next;
        (*L)->next = s; // 将新结点插入到表头
        scanf("%d", &x);
    }
    return *L;
}

void printList(LinkList L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    LinkList L;
    int temp = 0;

    int i = 0, e = 0;
    LNode *p;
    while (temp != 9999)
    {
        printf("请输入要操作的序号：\n1.插入\n2.删除\n3.输出\n4.按位查找\n5.按值查找\n6.创建链表\n-1.退出\n");
        scanf("%d", &temp);
        switch (temp)
        {
        case 1:
            printf("请输入要插入的位置和元素：\n");

            scanf("%d %d", &i, &e);
            ListInsert(&L, i, e);
            break;
        case 2:
            printf("请输入要删除的位置：\n");
            scanf("%d", &i);
            ListDelete(&L, i, &e);
            break;
        case 3:
            printList(L);
            break;
        case 4:
            printf("请输入要查找的位置：\n");
            scanf("%d", &i);
            p = GetElem(L, i);
            if (p != NULL)
                printf("第%d个元素是：%d\n", i, p->data);
            else
                printf("查找失败\n");
            break;
        case 5:
            printf("请输入要查找的元素：\n");
            scanf("%d", &e);
            p = LocateElem(L, e);
            if (p != NULL)
                printf("元素%d在第%d个位置\n", e, i);
            else
                printf("查找失败\n");
            break;
        case 6:
            List_HeadInsert(&L);
            break;
        case -1:
            return 0;
        default:
            break;
        }
    }

    return 0;
}