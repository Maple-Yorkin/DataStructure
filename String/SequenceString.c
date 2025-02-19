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
