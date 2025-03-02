#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> loc;
    vector<int> ans;

    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
            {
                loc.push_back(i);
            }
        }
        for (int i = 0; i < queries.size(); i++)
        {
            if (queries[i] - 1 < loc.size())
            {
                ans.push_back(loc[queries[i] - 1]);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums;
    vector<int> queries;
    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        nums.push_back(num);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        queries.push_back(num);
    }
    int x;
    cin >> x;
    Solution *solution = new Solution;
    vector<int> v = solution->occurrencesOfElement(nums, queries, x);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    return 0;
}