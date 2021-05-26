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
    int depth = 0;

    int dfs(TreeNode *root, int depth)
    {
        if (!root)
            return depth;
        if (root and !root->left and !root->right)
            return depth + 1;

        return min(dfs(root->left, depth + 1), dfs(root->right, depth + 1));
    }

    int minDepth(TreeNode *root)
    {

        if (!root)
            return 0;

        return dfs(root, 0);
    }
};

// BFS

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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int depth = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            depth++;
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                
                if(!node -> left and !node -> right)
                    return depth;
                
                if(node -> left)
                    q.push(node -> left);
                
                if(node -> right)
                    q.push(node -> right);
            }
        }
        
        return depth;
    }
};