#include <iostream>
#include <vector>
using namespace std;
const int maxn = 105;
class Solution
{
public:
    int a[maxn][maxn] = {0};
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1)
                break;
            a[0][i] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
                break;
            a[i][0] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    continue;
                a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
        return a[m - 1][n - 1];
    }
};

int main()
{
    return 0;
}