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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = nullptr;

        for (int data : preorder)
            bst(root, data);

        return root;
    }

    TreeNode *bst(TreeNode *&root, int data)
    {
        if (root == nullptr)
        {
            root = new TreeNode(data);
            return root;
        }

        if (data < root->val)
        {
            bst(root->left, data);
        }

        else
        {
            bst(root->right, data);
        }

        return root;
    }
};