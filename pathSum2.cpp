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
    void dfs(TreeNode *root, int& sum, int current_sum, vector<int> vec, vector<vector<int>>& sol){
        if(!root)
            return;
        
        current_sum += root->val;
        vec.push_back(root->val);
        
        if(current_sum == sum and !root->left and !root->right){
            sol.emplace_back(vec);
            return;
        }
        
        dfs(root->left, sum, current_sum, vec, sol);
        dfs(root->right, sum, current_sum, vec, sol);
        
        // vec.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> sol;
        if(root == nullptr)
            return sol;
        
        vector<int> vec;
        
        int current_sum = 0;
        
        dfs(root, sum, current_sum, vec, sol);
        
        return sol;
    }
};