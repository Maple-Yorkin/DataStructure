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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return v;
        if (root->left != NULL)
            inorderTraversal(root->left);
        visit(root);

        if (root->right != NULL)
            inorderTraversal(root->right);
        return v;
    }
};
int main()
{
}