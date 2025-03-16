#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isBalanced(string num)
    {
        int odd = 0;
        int even = 0;
        reverse(num.begin(), num.end());
        for (int i = 0; i < num.length(); i++)
        {
            if (i % 2 == 0)
            {
                odd += num[i] - '0';
            }
            else
            {
                even += num[i] - '0';
            }
        }
        return odd == even;
    }
};

int main()
{
}