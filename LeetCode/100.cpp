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
    int temp = 1;
    void dfs(TreeNode *p, TreeNode *q)
    {
        if (temp == 0 || p == NULL || q == NULL || p->val != q->val)
        {
            temp = 0;
            return;
        }

        if (p->left != NULL || q->left != NULL)
        {
            isSameTree(p->left, q->left);
        }
        if (p->right != NULL || q->right != NULL)
        {
            isSameTree(p->right, q->right);
        }
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        dfs(p, q);
        if (temp == 1)
            return 1;
        else
            return 0;
    }
};
int main()
{
}