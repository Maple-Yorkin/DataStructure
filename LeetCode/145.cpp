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
    vector<int> v;
    void visit(TreeNode *root)
    {
        v.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return v;
        if (root->left != NULL)
            postorderTraversal(root->left);

        if (root->right != NULL)
            postorderTraversal(root->right);
        visit(root);
        return v;
    }
};
int main()
{
}