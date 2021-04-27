/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int dfs(TreeNode *root, TreeNode *parent, TreeNode *grandparent)
    {
        if (!root)
            return 0;
        int sum = 0;
        if (grandparent and grandparent->val % 2 == 0)
            sum += root->val;

        sum += dfs(root->left, root, parent);
        sum += dfs(root->right, root, parent);

        return sum;
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        TreeNode *grandparent = nullptr, *parent = nullptr;
        return dfs(root, parent, grandparent);
    }
};