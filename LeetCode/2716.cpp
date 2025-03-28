#include <iostream>
#include <set>
using namespace std;
// 本题要将题干翻译成人话：删除相同字符
class Solution
{
public:
    set<char> st;
    int minimizedStringLength(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            st.insert(s[i]);
        }
        return st.size();
    }
};
int main()
{
}