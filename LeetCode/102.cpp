#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    queue<pair<TreeNode *, int>> q;
    vector<vector<int>> ans;
    int maxlevel = 0;
    TreeNode *now;
    int level;
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return ans;
        ans.resize(2005);
        q.push({root, 0});
        pair<TreeNode *, int> temp;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            now = temp.first;
            level = temp.second;
            if (level > maxlevel)
                maxlevel = level;
            ans[level].push_back(now->val);
            if (temp.first->left)
            {
                q.push({temp.first->left, temp.second + 1});
            }
            if (temp.first->right)
            {
                q.push({temp.first->right, temp.second + 1});
            }
        }
        ans.resize(maxlevel + 1);
        return ans;
    }
};

int main()
{
}