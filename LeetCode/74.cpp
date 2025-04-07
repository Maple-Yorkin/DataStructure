#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int a[10][10] = {0};
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int len = matrix[0].size();
        int h = matrix.size();
        int left = 0;
        int right = len * h - 1;
        int mid, midx, midy;
        while (left <= right)
        {
            mid = (left + right) / 2;
            midx = mid % len;
            midy = mid / len;
            if (matrix[midy][midx] == target)
                return true;
            else if (matrix[midy][midx] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            a[i][j] = 4 * i + j;
        }
    }
    int x;
    cin >> x;
    while (x != -1)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%02d ", a[i][j]);
            }
            cout << endl;
        }
        cout << "x: " << x % 4 << endl
             << "y: " << x / 4;
        system("cls");
        cin >> x;
    }
    return 0;
}
