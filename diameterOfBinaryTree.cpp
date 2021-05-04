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
    int res;
    
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        
        rec(root);
        
        return res;
    }
    
    int rec(TreeNode* root){
         if(root == nullptr)
            return 0;

        int l = rec(root->left);
        int r = rec(root->right);
        
        int temp = max(l, r) + 1;
        int ans = l + r;
        
        res = max(res, ans);
        
        return temp;
    }
};