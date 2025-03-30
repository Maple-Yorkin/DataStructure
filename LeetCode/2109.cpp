#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string ans = "";
        int now = 0;
        for (int i = 0; i < spaces.size(); i++)
        {
            ans += s.substr(now, spaces[i] - now);
            ans += ' ';
            now = spaces[i];
        }
        ans += s.substr(now, s.length() - now);
        return ans;
    }
};
int main()
{
    string str;
    cin >> str;
    cout << str.substr(0, 5);
    cout << str.substr(5, 4);
    return 0;
}