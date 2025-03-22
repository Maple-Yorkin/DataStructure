#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int max = 0;
        int ans = 0;
        int h = mat.size();
        int len = mat[0].size();
        int num = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (mat[i][j])
                    num++;
            }
            if (num > max)
            {
                ans = i;
                max = num;
            }
            num = 0;
        }
        vector<int> v;
        v.push_back(ans);
        v.push_back(max);
        return v;
    }
};