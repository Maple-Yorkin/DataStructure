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

    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return v;
        visit(root);
        if (root->left != NULL)
            preorderTraversal(root->left);

        if (root->right != NULL)
            preorderTraversal(root->right);
        return v;
    }
};

int main()
{
}