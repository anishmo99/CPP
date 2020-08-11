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
    bool dfs(TreeNode* root, int temp_sum, int sum){
        if(root == nullptr)
            return false;
        
        temp_sum += root->val;
        
        cout<<temp_sum<<" ";
        
        if(root->left == nullptr and root->right == nullptr and temp_sum == sum)
            return true;
        
        return dfs(root->left, temp_sum, sum) || dfs(root->right, temp_sum, sum);
        
        
        return false;
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, 0, sum);
    }
};