#include <stdio.h>
#include <stdlib.h>
// #define MaxSize 10
#define false 0
#define true 1
#define InitSize 10
// typedef struct {
//     int data[MaxSize];
//     int length;
// } SqList;

typedef struct
{
    int *data;
    int MaxSize;
    int length;
} SqList;
// 初始化表
void InitList(SqList *L)
{
    L->data = (int *)malloc(InitSize * sizeof(SqList)); // 将data指向的指针分配一个大小为InitSize的空间
    if (L->data == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    L->MaxSize = InitSize;
    L->length = 0;
}
// 扩大表大小
void IncreaseSize(SqList *L, int len)
{
    int *p = L->data;                                             // 将原本的data指针取出来
    L->data = (int *)malloc((L->MaxSize + len) * sizeof(SqList)); // 重新分配一个新的空间，并赋值给原本的data指针
    if (L->data == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    for (int i = 0; i < L->length; i++) // 将原本位置的所有元素复制到新分配的空间
    {
        L->data[i] = p[i];
    }
    L->MaxSize += len;
    free(p); // 最后将原本的空间释放
    printf("增加成功\n");
}
// 在第i位插入元素e
int ListInsert(SqList *L, int i, int e)
{
    if (i < 1 || i > L->length + 1)
    {
        printf("位置错误\n");
        return false;
    }
    if (L->length >= L->MaxSize)
    {
        printf("顺序表已满\n");
        return false;
    }
    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1]; // 将第i个元素及其之后的元素后移
    }
    L->data[i - 1] = e; // 在位置i处放入e
    L->length++;        // 长度+1
    return true;
}
// 删除第i位元素
int ListDelete(SqList *L, int i, int *e)
{
    if (i < 1 || i > L->length) // 判断i的范围是否有效
    {
        printf("位置错误\n");
        return false;
    }
    *e = L->data[i - 1]; // 将被删除的元素赋值给e
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j]; // 将第i个元素之后的元素前移
    }
    L->length--; // 长度-1
    return true;
}
// 输出表
void ListPrint(SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d\n", L->data[i]);
    }
    printf("\n");
}
// 按位查找
int GetElem(SqList *L, int i, int *e)
{
    if (i < 1 || i > L->length)
    {
        printf("位置错误\n");
        return false;
    }
    *e = L->data[i - 1];
    return true;
}
// 按值查找
int LocateElem(SqList *L, int e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return false;
}

int main()
{
    SqList L;
    InitList(&L);
    int temp = 0;
    while (temp != -1)
    {
        printf("请输入要操作的序号：\n1.插入\n2.删除\n3.输出\n4.按位查找\n5.按值查找\n-1.退出\n");
        scanf("%d", &temp);
        switch (temp)
        {
        case 1:
            printf("请输入要插入的位置和元素：\n");
            int i, e;
            scanf("%d %d", &i, &e);
            ListInsert(&L, i, e);
            break;
        case 2:
            printf("请输入要删除的位置：\n");
            int j;
            scanf("%d", &j);
            ListDelete(&L, j, &temp);
            break;
        case 3:
            ListPrint(&L);
            break;
        case 4:
            printf("请输入要查找的位置：\n");
            int k;
            scanf("%d", &k);
            GetElem(&L, k, &temp);
            printf("第%d位的元素是：%d\n", k, temp);
            break;
        case 5:
            printf("请输入要查找的元素：\n");
            int m;
            scanf("%d", &m);
            temp = LocateElem(&L, m);
            if (temp)
            {
                printf("元素%d在第%d位\n", m, temp);
            }
            else
            {
                printf("未找到元素%d\n", m);
            }
            break;
        case -1:
            break;
        }
    }

    return 0;
}