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
    
    vector<int> vec;
    
    void into(TreeNode *root)
    {
        if(root==NULL)
            return;
        into(root->left);
        vec.push_back(root->val);
        into(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        into(root);
        sort(vec.begin(),vec.end());
        int size=vec.size();
        int ke=vec[k-1];
        vec.clear();
        if(k>size)
            return -1;
        return ke;
    }
};
