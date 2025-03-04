#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Solution
{
public:
    queue<int> q;
    // 注意题目要求的length
    int dp[10005] = {0};

    int jump(vector<int> &nums)
    {
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            int size = nums[i];
            for (int j = i; j <= i + size; j++)
            {
                if (j < len)
                    dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        return dp[len - 1];
    }
};

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    Solution *solution = new Solution;
    cout << solution->jump(v);

    return 0;
}