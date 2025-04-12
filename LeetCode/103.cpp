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
    deque<pair<TreeNode *, int>> q;
    vector<vector<int>> ans;
    int level = 0;
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return ans;
        ans.resize(205);
        q.push_back({root, 0});
        pair<TreeNode *, int> p;
        int nowlevel;
        TreeNode *nownode;
        while (!q.empty())
        {
            level = min(q.front().second, q.back().second);
            if (level % 2) // 从后端出
            {
                p = q.back();
                q.pop_back();
                nownode = p.first;
                nowlevel = p.second;
                ans[nowlevel].push_back(nownode->val);
                if (nownode->right)
                    q.push_front({nownode->right, nowlevel + 1});
                if (nownode->left)
                    q.push_front({nownode->left, nowlevel + 1});
            }
            else // 从前端出
            {
                p = q.front();
                q.pop_front();
                nownode = p.first;
                nowlevel = p.second;
                ans[nowlevel].push_back(nownode->val);
                if (nownode->left)
                    q.push_back({nownode->left, nowlevel + 1});
                if (nownode->right)
                    q.push_back({nownode->right, nowlevel + 1});
            }
                }
        ans.resize(level + 1);
        return ans;
    }
};
int main()
{
}