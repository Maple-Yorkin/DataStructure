#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 这道题要写好check函数
    bool check(vector<int> &piles, int h, int k)
    {
        int ans = 0;
        // 如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。
        // 说明吃一堆香蕉实际上是向上取整
        // 可以通过ceil向上取整
        for (int i = 0; i < piles.size(); i++)
        {
            ans += (piles[i] + k - 1) / k;
            // 如果超出了时限就false
            if (ans > h)
            {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // 边界是[1, 1e9]
        int left = 1;
        int right = 1e9 + 5;
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (check(piles, h, mid))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        // 最后一步的时候，left==right==mid，此时这些数据就是符合check的
        // 因此check里面right=mid-1
        // 而下一步中，mid已经变成了right（整数除法向下取整）
        // 这样就应该return left而不是mid
        return left;
    }
};
int main()
{
}