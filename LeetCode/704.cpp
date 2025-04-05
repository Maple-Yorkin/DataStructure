#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 获取长度
        int len = nums.size();
        int left = 0;        // 左端
        int right = len - 1; // 右端
        int mid;             // 区间的中间，向下取整
        while (left <= right)
        {
            mid = (left + right) / 2; // 每一轮都根据区间重新调整mid
            if (nums[mid] == target)  // 如果刚好相等，则直接返回mid
                return mid;
            else if (nums[mid] > target) // 如果mid处的值大于target，说明target应该在mid左侧
                right = mid - 1;         // 因此将右侧收缩到mid-1（因为也不会是在mid处）
            else
                left = mid + 1; // 同理mid处大于target，说明target在mid右侧，将左侧收缩到mid+1
        }
        return -1; // 如果找不到（此时左端跑到了右端的右侧），则返回-1
    }
};

int main()
{
}