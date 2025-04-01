#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    long long ans = 0;

    long long mostPoints(vector<vector<int>> &questions)
    {
        int len = questions.size();
        long long *a = new long long[len + 5];
        for (int i = len - 1; i >= 0; i--)
        {
            ans = questions[i][0]; // 解决
            long long bp = i + questions[i][1] + 1;
            if (bp < len)
                ans += a[bp];
            a[i] = max(a[i + 1], ans);
        }
        return a[0];
    }
};
int main()
{
}