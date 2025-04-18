#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    short isvisited[105] = {0};
    bool isPossibleToSplit(vector<int> &nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {

            if (isvisited[nums[i]] == 0)
            {
                isvisited[nums[i]] = 1;
            }
            else if (isvisited[nums[i]] == 1)
            {
                isvisited[nums[i]] = 2;
            }
            else
                return false;
        }
        return true;
    }
};
int main()
{
}