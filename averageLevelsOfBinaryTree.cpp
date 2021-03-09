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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        if(!root)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        double avg;
        long long int sum = root -> val;
        
        while(!q.empty()){
            int size = q.size();
            
            avg = (double)sum / size;
            ans.push_back(avg);
            
            sum = 0;
            
            for(int i = 0; i < size; i++){
                auto x = q.front();
                q.pop();
                if(x -> left){
                    q.push(x ->left);
                    sum += x -> left -> val;
                }
                if(x -> right){
                    q.push(x -> right);
                    sum += x -> right -> val;
                }
            }
        }
        return ans;
    }
};