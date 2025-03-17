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
        int now = 0;
        int p = 0;
        for (now = 0; now < pushed.size(); now++)
        {
            s.push(pushed[now]);
            while (!s.empty() && s.top() == popped[p])
            {
                p++;
                s.pop();
            }
        }
        if (s.empty())
            return true;
        return false;
    }
};
int main()
{
}