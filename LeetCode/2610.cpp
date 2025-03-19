#include <iostream>
#include <vector>
using namespace std;
class Solution
{

public:
    int count[205] = {0};
    int check(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            if (count[i])
                return 1;
        }
        return 0;
    }
    vector<vector<int>> v;
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }
        int len = nums.size();
        while (check(len))
        {
            vector<int> tempv;
            for (int i = 0; i <= len; i++)
            {

                if (count[i])
                {
                    tempv.push_back(i);
                    count[i]--;
                }
            }
            v.push_back(tempv);
            tempv.clear();
        }
        return v;
    }
};

int main()
{
    Solution *solution = new Solution();

    return 0;
}