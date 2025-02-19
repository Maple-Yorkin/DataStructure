typedef struct StringNode
{
    char ch; // 每个结点存储一个字符
    struct StringNode *next;

} StringNode, *String;
// 这种存储方法每个字符1B，而每个指针高达4B，存储密度较低

typedef struct StringNode
{
    char ch[4]; // 每个结点存储四个字符。实际上可以更多
    struct StringNode *next;
} StringNode, *String;
// 如果使用到最后一个结点时无法填充满该结点的数组，可以填充特殊字符
