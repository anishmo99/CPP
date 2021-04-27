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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            if(!left and !right)
                continue;
            
            if(!left or !right)
                return false;
            
            if(left->val != right->val)
                return false;
            
            q.push(left->left);
            q.push(right->right);
            
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};

// OR

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
    bool dfs(TreeNode* nleft, TreeNode* nright){
        if(!nleft and !nright)
            return true;
        
        if(!nleft or !nright)
            return false;
        
        return nleft -> val == nright -> val and dfs(nleft -> left, nright -> right) and dfs(nleft -> right, nright -> left);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root -> left, root -> right);
    }
};