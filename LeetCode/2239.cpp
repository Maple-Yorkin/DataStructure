#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        int minnum = 0x3f3f3f3f;
        int maxnum = 0x3f3f3f3f;
        int minindex = 0;
        int maxindex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                return nums[i];
            if (nums[i] < 0 && abs(nums[i]) < minnum)
            {
                minnum = abs(nums[i]);
                minindex = i;
            }
            else if (nums[i] > 0 && nums[i] < maxnum)
            {
                maxnum = nums[i];
                maxindex = i;
            }
        }
        if (minnum + maxnum == 0)
            return maxnum;
        if (abs(minnum) < maxnum)
            return nums[minindex];
        else
            return nums[maxindex];
    }
};
int main()
{
}