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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> sol;
        if(!root)
            return sol;
        
        stack<TreeNode*> s;
        
        s.push(root);
        
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            
            if(temp){
                sol.push_back(temp -> val);
                
                s.push(temp -> left);
                s.push(temp -> right);
            }
        }
        
        reverse(sol.begin(), sol.end());
        
        return sol;
    }
};