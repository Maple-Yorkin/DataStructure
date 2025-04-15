#include <iostream>

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
    int minnum = 0x3f3f3f3f;
    void dfs(TreeNode *root, int level)
    {
        if (root->left == NULL && root->right == NULL && level < minnum)
        {
            minnum = level;
        }
        if (root->left)
        {
            dfs(root->left, level + 1);
        }
        if (root->right)
        {
            dfs(root->right, level + 1);
        }
    }
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        dfs(root, 1);
        return minnum;
    }
};
int main()
{
}