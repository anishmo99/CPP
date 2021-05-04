class Solution {
private:
    int solve(TreeNode* root, int& maxsum) {
        if(!root) return 0;
        
        int l = solve(root->left, maxsum);
        int r = solve(root->right, maxsum);
        
        int temp = max(0, root -> val + max(l, r));
        
        int ans = root -> val + l + r;
        
        maxsum = max(maxsum, ans);
        
        return temp;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        
        solve(root, maxsum);
        
        return maxsum;
    }
};


// or

class Solution {
private:
    int solve(TreeNode* root, int& maxsum) {
        if(!root) return 0;
        
        int l = solve(root->left, maxsum);
        int r = solve(root->right, maxsum);
        
        int temp = max(root -> val, root -> val + max(l, r));
        
        int ans = max(temp, root -> val + l + r);
        
        maxsum = max(maxsum, ans);
        
        return temp;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        
        solve(root, maxsum);
        
        return maxsum;
    }
};

