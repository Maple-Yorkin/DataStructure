#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    stack<int> s;
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int now = 0;                              // 指向pushed的指针
        int p = 0;                                // 指向popped的指针
        for (now = 0; now < pushed.size(); now++) // 在pushed中遍历
        {
            s.push(pushed[now]);
            while (!s.empty() && s.top() == popped[p]) // 每次压入元素就判断顶部是否与p的指向元素相同，只要有可以弹出的就进行弹出
            {
                // 如果相同则p++，并弹出栈顶元素（说明可以有当前这个序列）
                p++;
                s.pop();
            }
        }
        // 如果运行到最后可以让栈为空，也就是说可以有输出序列而栈中没有剩下的元素
        if (s.empty())
            return true;
        return false;
    }
};
int main()
{
}