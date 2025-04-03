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
    int dfs(TreeNode *root)
    {
        if (root->left != NULL)
            ans += dfs(root->left);
        if (root->right != NULL)
            dfs(root->right);
        if (root->left == NULL && root->right == NULL)
            return root->val;
        return 0;
    }
    int ans = 0;
    int sumOfLeftLeaves(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};
int main()
{
}