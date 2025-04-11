#include <iostream>
#include <vector>
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
    int deepth = 0;
    void dfs(TreeNode *root, int level)
    {
        if (deepth < level)
            deepth = level;
        if (root->left)
        {
            dfs(root->left, level + 1);
        }
        if (root->right)
        {
            dfs(root->right, level + 1);
        }
    }
    int maxDepth(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }
        dfs(root, 1);
        return deepth;
    }
};
int main()
{
}