#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> temp;
    void print()
    {
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i];
        }
    }
    int divisorSubstrings(int num, int k)
    {
        temp.clear();
        int beauty = 0;
        int tempnum = num;
        while (tempnum)
        {
            temp.push_back(tempnum % 10);
            tempnum /= 10;
        }

        for (int i = 0; i + k - 1 < temp.size(); i++)
        {
            tempnum = 0;
            for (int j = k - 1; j >= 0; j--)
            {
                tempnum += pow(10, j) * temp[j + i];
            }
            if (tempnum != 0 && num % tempnum == 0)
                beauty++;
        }
        return beauty;
    }
};
int main()
{
    Solution *solution = new Solution;
    cout << solution->divisorSubstrings(240, 2) << endl;
    cout << solution->divisorSubstrings(430043, 2);
    return 0;
}