// leetcode

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root);
        while (!s1.empty() or !s2.empty())
        {
            vector<int> cur_level;
            while (!s1.empty())
            {
                root = s1.top();
                s1.pop();
                cur_level.push_back(root->val);
                if (root->left)
                    s2.push(root->left);
                if (root->right)
                    s2.push(root->right);
            }
            if (!cur_level.empty())
                result.emplace_back(cur_level);
            cur_level.clear();
            while (!s2.empty())
            {
                root = s2.top();
                s2.pop();
                cur_level.push_back(root->val);
                if (root->right)
                    s1.push(root->right);
                if (root->left)
                    s1.push(root->left);
            }
            if (!cur_level.empty())
                result.emplace_back(cur_level);
        }
        return result;
    }
};