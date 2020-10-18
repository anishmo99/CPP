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
    bool dfs(TreeNode *root, TreeNode *low, TreeNode *high)
    {
        if (!root)
            return true;

        if (low and root->val and root->val <= low->val)
            return false;

        if (high and root->val and root->val >= high->val)
            return false;

        return dfs(root->left, low, root) and dfs(root->right, root, high);
    }

    bool isValidBST(TreeNode *root)
    {
        return dfs(root, nullptr, nullptr);
    }
};