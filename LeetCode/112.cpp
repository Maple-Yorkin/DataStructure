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
    int temp = 0;
    int target = 0;
    void search(TreeNode *node, int sum)
    {

        sum += node->val;
        if (node->left == NULL && node->right == NULL && sum == target)
        {
            temp = 1;
        }
        else
        {
            if (!(node->left == NULL))
                search(node->left, sum);
            if (!(node->right == NULL))
                search(node->right, sum);
        }
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        target = targetSum;
        if (root == NULL)
            return false;
        else
            search(root, 0);
        return temp;
    }
};

int main()
{
}