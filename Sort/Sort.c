#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAXLEN 255
// 直接插入排序
void InsertSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) // 将各元素插入已排好序的序列中
    {
        if (A[i] < A[i - 1]) // 若A[i]关键字小于前驱
        {
            temp = A[i];                                // 用temp暂存A[i]
            for (j = i - 1; j >= 0 && A[j] > temp; --j) // 检查所有前面已经排好序的元素
            {
                A[j + 1] = A[j]; // 所有大于temp的元素都向后挪位
            }
            A[j + 1] = temp; // 复制到插入位置
        }
    }
}
// 直接插入排序（带哨兵）
void InsertSort(int A[], int n)
{
    int i, j;
    for (i = 2; i <= n; i++) // 依次将A[2]~A[n]插入到前面已排序序列
    {
        if (A[i] < A[i - 1]) // 若A[i]关键码小于其前驱，将A[i]插入有序表
        {
            A[0] = A[i];                      // 复制为哨兵，A[0]不存放元素
            for (j = i - 1; A[0] < A[j]; --j) // 从后往前查找待插入位置
                A[j + 1] = A[j];              // 向后挪位
            A[j + 1] = A[0];                  // 复制到插入位置
        }
    }
}
// 折半插入排序
void InsertSort(int A[], int n)
{
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++) // 依次将A[2]~A[n]插入前面的已排序序列
    {
        A[0] = A[i]; // 将A[i]暂存
        low = 1;
        high = i - 1;       // 设置折半查找的范围
        while (low <= high) // 折半查找（递增有序的情况）
        {
            mid = (low + high) / 2; // 取中间点
            if (A[mid] > A[0])
                high = mid - 1; // 查找左半子表
            else
                low = mid + 1; // 查找右半子表
        }
        for (j = i - 1; j >= high + 1; --j)
        {
            A[j + 1] = A[j]; // 统一后移元素，空出插入位置
        }
        A[high + 1] = A[0]; // 插入操作
    }
}
// 希尔排序Shell Sort
void ShellSort(int A[], int n)
{
    int d, i, j;
    // A[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
    for (d = n / 2; d >= 1; d = d / 2) // 步长变化
    {
        for (i = d + 1; i <= n; ++i)
        {
            if (A[i] < A[i - d]) // 将A[i]插入有序增量子表
            {
                A[0] = A[i]; // 暂存
                for (j = i - d; j > 0 && A[0] < A[j]; j -= d)
                {
                    A[j + d] = A[j]; // 记录后移，查找插入的位置
                }
                A[j + d] = A[0]; // 插入
            }
        }
    }
}
// 冒泡排序用到的交换函数
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 冒泡排序
void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = false;
        for (int j = n - 1; j > i; j--)
        {
            if (A[j - 1] > A[j])
            {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
        if (flag == false)
            return;
    }
}
// 快速排序
// 用第一个元素的最终位置将待排序序列划分成左右两个部分
int Partition(int A[], int low, int high)
{
    int pivot = A[low]; // 第一个元素作为枢轴
    while (low < high)  // 用low和high搜索枢轴的最终位置
    {
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high]; // 比枢轴小的元素移动到左端
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low]; // 比枢轴大的元素移动到右端
    }
    A[low] = pivot; // 枢轴元素存放到最终位置
    return low;     // 返回存放枢轴的最终位置
}
void QuickSort(int A[], int low, int high)
{
    if (low < high) // 递归跳出
    {
        int pivotpos = Partition(A, low, high); // 进行划分
        QuickSort(A, low, pivotpos - 1);        // 划分排序左子表
        QuickSort(A, pivotpos + 1, high);       // 划分排序右子表
    }
}
// 简单选择排序
void SelectSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) // 一共进行n-1趟
    {
        int min = i;                    // 记录最小元素的位置
        for (int j = i + 1; j < n; j++) // 在A[i...n-1]中选择最小的元素
        {
            if (A[j] < A[min])
                min = j; // 更新最小元素位置
        }
        if (min != i)
            swap(A[i], A[min]); // 封装的swap()函数内部共移动元素三次
    }
}