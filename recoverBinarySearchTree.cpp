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
    void fixTree(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second)
    {
        if (root)
        {
            fixTree(root->left, prev, first, second);

            if (prev and prev->val > root->val)
            {
                if (!first)
                {
                    first = prev;
                    second = root;
                }
                else
                {
                    second = root;
                }
            }

            prev = root;

            fixTree(root->right, prev, first, second);
        }
    }
    void recoverTree(TreeNode *root)
    {
        if (!root)
            return;

        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;

        fixTree(root, prev, first, second);

        swap(first->val, second->val);
    }
};