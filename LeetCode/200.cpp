#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class Solution
{
public:
    int dirx[4] = {1, 0, -1, 0};
    int diry[4] = {0, 1, 0, -1};
    queue<pair<int, int>> q; // x, y
    int ans = 0;
    int count = 0;
    bool visited[3005][3005] = {0};
    void bfs(vector<vector<char>> &grid, int nowx, int nowy, int len, int h)
    {
        count++;
        q.push({nowx, nowy});
        visited[nowy][nowx] = true;
        pair<int, int> now;
        int x;
        int y;
        int nextx, nexty;
        while (!q.empty())
        {
            now = q.front();
            q.pop();
            x = now.first;
            y = now.second;
            cout << x << ' ' << y << endl;
            grid[y][x] = '0';
            for (int i = 0; i < 4; i++)
            {
                nextx = x + dirx[i];
                nexty = y + diry[i];
                if (nexty >= 0 && nexty < h && nextx >= 0 && nextx < len)
                {
                    if (visited[nexty][nextx] == false && grid[nexty][nextx] == '1')
                    {
                        q.push({nextx, nexty});
                        visited[nexty][nextx] = true;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int len = grid[0].size();
        int h = grid.size();
        for (int i = 0; i < h; i++) // y
        {
            for (int j = 0; j < len; j++) // x
            {
                if (visited[i][j] == false && grid[i][j] == '1')
                    bfs(grid, j, i, len, h);
            }
        }

        return count;
    }
};
int main()
{
    Solution *solution = new Solution;
    vector<vector<char>> grid;

    int len, h;
    cin >> len >> h;
    grid.resize(h);
    char now;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cin >> now;
            grid[i].push_back(now);
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << solution->numIslands(grid);
    return 0;
}