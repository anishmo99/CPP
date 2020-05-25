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
class Solution {
public:
    TreeNode* bst(TreeNode* &root,int data)
    {
        if(root==NULL)
        {
            root=new TreeNode();
            root->val=data;
            return root;
        }
        if(data<root->val)
            bst(root->left,data);
        else
            bst(root->right,data);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root=NULL;
        for(int& data:preorder)
            bst(root,data);
            
        return root;
    }
};
