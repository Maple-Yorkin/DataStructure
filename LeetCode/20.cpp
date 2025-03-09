#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    stack<char> st;
    bool isValid(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                char c = st.top();

                if ((s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') || (s[i] == ']' && c == '['))
                {
                    st.pop();
                }
                else
                    return false;
            }
        }
        if (st.empty())
        {
            return true;
        }
        else
            return false;
    }
};

int main()
{
    return 0;
}