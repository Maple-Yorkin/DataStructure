#include <iostream>
#include <vector>
using namespace std;
bool isBadVersion(int version)
{
    //...
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;
        int mid;
        while (left < right)
        {
            mid = left + (right - left) / 2; // 二分法用这种方法更好，这样可以避免left+right之后超出数据范围
            if (isBadVersion(mid) == false)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return right;
    }
};

int main()
{
}