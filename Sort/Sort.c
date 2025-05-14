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
// 建立大根堆
void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; i--) // 从后往前调整所有非终端节点
    {
        HeadAdjust(A, i, len);
    }
}
// 将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len)
{
    A[0] = A[k];                          // A[0]暂存子树的根节点
    for (int i = 2 * k; i <= len; i *= 2) // 沿着key较大的子节点向下筛选
    {
        if (i < len && A[i] < A[i + 1])
        {
            i++; // 取key较大的子节点的下标
        }
        if (A[0] >= A[i])
            break; // 筛选结束
        else
        {
            A[k] = A[i]; // 将A[i]调整到双亲结点上
            k = i;       // 修改k值，以便继续乡下筛选
        }
    }
    A[k] = A[0]; // 被筛选结点的值放入最终位置
}
// 堆排序的逻辑
void HeapSort(int A[], int len)
{
    BuildMaxHeap(A, len);         // 初始化大根堆
    for (int i = len; i > 1; i--) // n-1趟的交换和建堆过程
    {
        swap(A[i], A[1]);        // 堆顶元素和堆底元素互换
        HeadAdjust(A, 1, i - 1); // 把剩余的待排序元素整理成堆
    }
}
// 归并排序
void Merge(int A[], int low, int mid, int high, int n)
{
    // 将有序的A[low...mid]和A[mid+1...high]两部分归并
    int *B = (int *)malloc(n * sizeof(int)); // 辅助数组B
    int i, j, k;
    for (k = low; k <= high; k++)
    {
        B[k] = A[k]; // 将A中所有元素复制到B中
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
            A[k] = B[i++]; // 将较小的值复制到A中
        else
            A[k] = B[j++];
    }
    while (i <= mid)
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[j++];
}
void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;           // 从中间划分
        MergeSort(A, low, mid);               // 对左半部分归并排序
        MergeSort(A, mid + 1, high);          // 对右半部分归并排序
        Merge(A, low, mid, high, high - low); // 归并
    }
}
// 计数排序
// A是输入数组（待排序数组），B是输出数组，n是A[]的长度，k反应A[]的取值范围
void CountSort(int A[], int B[], int n, int k)
{
    int i, C[k];            // 辅助数组C的长度取决于待排序元素取值范围[0,k)
    for (i = 0; i < k; i++) // 初始化计数数组C
        C[i] = 0;
    for (i = 0; i < n; i++) // 步骤一：遍历排序数组，统计每个关键字的出现次数
        C[A[i]]++;
    for (i = 1; i < k; i++)      // 步骤二：再次处理辅助数组，统计不大于i的元素个数
        C[i] = C[i] + C[i - 1];  // C[i]保存的是小于等于i的元素个数
    for (i = n - 1; i >= 0; i--) // 步骤三：利用辅助数组C实现计数排序（从后向前处理，保证稳定性）
        C[A[i]] = C[A[i]] - 1;
    B[C[A[i]]] = A[i]; // 将元素A[i]放入输出数组B[]的正确位置上
}