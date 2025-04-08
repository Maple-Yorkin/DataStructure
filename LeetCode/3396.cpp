#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int num[105] = {0};
    int minimumOperations(vector<int> &nums)
    {
        int len = nums.size();
        int count = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (num[nums[i]] == 0)
            {
                num[nums[i]] = 1;
                count++;
            }
            else
            {
                break;
            }
        }
        int a = len - count;
        return a % 3 ? a / 3 + 1 : a / 3;
    }
};
int main()
{
}