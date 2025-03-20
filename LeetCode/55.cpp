#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10005;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int maxnum = 0 + nums[0]; // 可以跳到maxnum的位置
        int len = nums.size();
        if (len == 1)
            return true;

        for (int i = 1; i <= maxnum; i++)
        {
            if (maxnum >= len - 1)
                break;
            maxnum = max(maxnum, i + nums[i]);
        }
        if (maxnum >= len - 1)
            return true;
        return false;
    }
};
int main()
{
}