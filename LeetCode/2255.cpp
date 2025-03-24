#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int countPrefixes(vector<string> &words, string s)
    {
        int ans = 0;
        int temp = 0;
        int len = s.length();
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {

                if (words[i][j] != s[j])
                {
                    temp = 0;
                    break;
                }
                else
                    temp = 1;
            }

            if (words[i].length() > len)
                temp = 0;
            if (temp == 1)
            {
                cout << words[i] << ' ';
                ans++;
            }
            temp = 0;
        }
        return ans;
    }
};
int main()
{
    string s;
    vector<string> v;
    string word;
    cin >> word;
    while (word != "-1")

    {
        v.push_back(word);
        cin >> word;
    }
    cin >> s;
    Solution *solution = new Solution;
    solution->countPrefixes(v, s);
    return 0;
}