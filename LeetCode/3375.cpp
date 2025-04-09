#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution
{
public:
    set<int> s;
    int minOperations(vector<int> &nums, int k)
    {
        // 这道题描述中的对于每个下标i，指的就是有几个变几个，如数组中有3个5，则如果选中5时将5全变
        // 因此直接用set去重再观察“合法性”
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int minnum = *s.begin();
        if (minnum < k)
            return -1;
        else if (minnum == k)
            return s.size() - 1;
        else
            return s.size();
        return -1;
    }
};
int main() {

};
