#include <iostream>
#include <vector>

using namespace std;

class Allocator
{
public:
    struct SegmentTable
    {
        int head;
        int length = 0;
        SegmentTable(int h, int l) : head(h), length(l) {}
    };
    int maxlen;
    vector<int> MemoryTable;
    vector<vector<struct SegmentTable>> allocatedMemoryTable;
    void print(vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << "头：" << i << " 长度：" << MemoryTable[i] << endl;
        }
    }
    void print(vector<vector<struct SegmentTable>> v, int mID)
    {
        for (auto i : v[mID])
        {
            cout << "头：" << i.head << " 长度：" << i.length << endl;
        }
    }
    Allocator(int n)
    {
        maxlen = n;
        // 初始化内存块表全部为-1，表示已分配；0表示未分配，>0表示未分配且是对应内存块的头（用来存储长度）
        MemoryTable = vector<int>(n);
        MemoryTable[0] = n;
        allocatedMemoryTable = vector<vector<struct SegmentTable>>(1005);
    }
    int allocate(int size, int mID)
    {

        for (int i = 0; i < maxlen; i++)
        {

            // 如果内存块大小足够分配
            if (MemoryTable[i] >= size)
            {

                // mID对应的内存分配表添加对应的段
                allocatedMemoryTable[mID].push_back(SegmentTable(i, size));
                // 内存块表进行对应处理

                if (i + size < maxlen && MemoryTable[i] > size)
                {
                    // 原本的块分配完剩下的赋值一个长度
                    MemoryTable[i + size] = MemoryTable[i] - size;
                }
                for (int j = i; j < i + size; j++)
                {
                    // 分配出去的对应的块赋值为-1
                    MemoryTable[j] = -1;
                }
                return i;
            }
        }
        return -1;
    }

    int freeMemory(int mID)
    {
        // 首先获取将要释放的内存单元数目
        int size = allocatedMemoryTable[mID].size();
        int count = 0;
        if (size == 0)
            return 0;
        // 对于每一个要释放的内存单元
        vector<struct SegmentTable>::iterator it;
        for (int i = 0; i < allocatedMemoryTable[mID].size(); i++)
        {
            it = allocatedMemoryTable[mID].begin() + i;
            count += it->length;
        }
        for (int i = 0; i < allocatedMemoryTable[mID].size(); i++)
        {
            it = allocatedMemoryTable[mID].begin() + i;
            // 获取它的头和长度
            int head = it->head;
            int length = it->length;
            // 如果内存块右侧有空闲的内存块
            if (head + length < maxlen && MemoryTable[head + length] > 0)
            {
                // 进行合并
                length += MemoryTable[head + length];
            }
            // 如果内存块左侧有空闲的内存块
            while (head - 1 >= 0 && MemoryTable[head - 1] >= 0)
            {
                // 进行合并
                head--;
                length++;
            }
            // 最后得到合并后的长度，将对应内存块内所有位置置为0（未分配），将头部置为合并后的长度
            MemoryTable[head] = length;
            for (int j = head + 1; j < head + length; j++)
            {
                MemoryTable[j] = 0;
            }
        }
        allocatedMemoryTable[mID].clear();
        return count;
    }
};
int main()
{
    int n;
    cin >> n;
    Allocator *allocator = new Allocator(n);
    string s;
    cin >> s;
    while (s != "-1")
    {
        if (s == "a")
        {
            int size, mID;
            cin >> size >> mID;
            cout << allocator->allocate(size, mID) << ' ';
        }
        else if (s == "f")
        {
            int mID;
            cin >> mID;
            cout << allocator->freeMemory(mID) << ' ';
        }
        else if (s == "pm")
        {
            allocator->print(allocator->MemoryTable);
        }
        else if (s == "pam")
        {
            int mID;
            cin >> mID;
            allocator->print(allocator->allocatedMemoryTable, mID);
        }
        cin >> s;
    }
    return 0;
}