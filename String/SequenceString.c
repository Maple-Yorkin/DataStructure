#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAXLEN 255
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

typedef struct
{
    char *ch;
    int length;
} HString; // headstring

int SubString(SString *Sub, SString S, int pos, int len)
{
    // 子串范围越界
    if (pos + len - 1 > S.length)
    {
        return false;
    }

    for (int i = pos; i < pos + len; i++)
    {
        Sub->ch[i - pos + 1] = S.ch[i];
    }
    Sub->length = len;
    return true;
}
// 比较串
int StrCompare(SString S, SString T)
{
    // 先对比有数值的部分
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        // 如果S不等于T，就进行比较
        if (S.ch[i] != T.ch[i])
        {
            return S.ch[i] - T.ch[i];
        }
    }
    // 如果扫描过的所有字符都相同，就看谁更长
    return S.length - T.length;
}

// 朴素模式匹配算法
int Match(SString S, SString T)
{
    int i = 1;
    int j = 1;
    // 如果主串指针i的位置不超过主串的长度，而且模式串指针j的位置不超过模式串的长度就进行匹配
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            // 指针后退重新开始匹配
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length)
    {
        return i - T.length;
    }
    else
    {
        return 0;
    }
}

int Index(SString S, SString T)
{
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub; // 暂存子串
    while (i <= n - m + 1)
    {
        SubString(&sub, S, i, m);
        if (StrCompare(sub, T) != 0)
        {
            i++;
        }
        else
        {
            return i; // 返回子串在主串中的位置
        }
    }
}
int main()
{
    HString S;
    // 手动堆分配存储，用完需要手动free
    S.ch = (char *)malloc(MAXLEN * sizeof(char));
    S.length = 0;
}
