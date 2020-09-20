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
    struct info
    {
        int subtree_sum;
        int max;
        int min;
        int largestBSTBT_sum;
        bool isBST;
    };

private:
    int ans = 0;
    info maxSumBSTBT(TreeNode *root)
    {
        if (!root)
            return {0, INT_MIN, INT_MAX, 0, true};

        if (!root->left and !root->right)
            return {root->val, root->val, root->val, root->val, true};

        info left = maxSumBSTBT(root->left);
        info right = maxSumBSTBT(root->right);

        info sol;
        sol.subtree_sum = (root->val + left.subtree_sum + right.subtree_sum);

        if (left.isBST and left.max < root->val and right.isBST and right.min > root->val)
        {
            sol.isBST = true;
            sol.largestBSTBT_sum = sol.subtree_sum;
            sol.min = min(left.min, root->val);
            sol.max = max(right.max, root->val);

            ans = max(sol.largestBSTBT_sum, ans); //added

            return sol;
        }

        sol.isBST = false;
        sol.largestBSTBT_sum = max(left.largestBSTBT_sum, right.largestBSTBT_sum);

        ans = max(sol.largestBSTBT_sum, ans); // added

        return sol;
    }

public:
    int maxSumBST(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(maxSumBSTBT(root).largestBSTBT_sum, ans); //updated
    }
};


// OR below is the fastest submission

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
    struct Result {
        int minVal, maxVal, sum;
        bool valid;
    };
    
    int ret = INT_MIN;

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return max(0, ret);
    }

    Result helper(TreeNode *root) {
        if (!root)
            return {INT_MAX, INT_MIN, 0, true};
        
        Result left = helper(root->left),
               right = helper(root->right);

        if (left.valid && right.valid && left.maxVal < root->val && right.minVal > root->val) {
            
            int sum = root->val + left.sum + right.sum;
            ret = max(ret, sum);
            
            return {min(root->val, left.minVal),
                    max(root->val, right.maxVal),
                    sum,
                    true};
        }
        return {0, 0, 0, false};
    }
};