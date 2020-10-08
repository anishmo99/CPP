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
    vector<pair<TreeNode *, int>> res;

public:
    void dfs(TreeNode *node, TreeNode *root, int depth, int x, int y)
    {
        if (!node)
            return;

        if (node->val == x)
        {
            res.emplace_back(root, depth);
        }

        if (node->val == y)
        {
            res.emplace_back(root, depth);
        }

        dfs(node->left, node, depth + 1, x, y);
        dfs(node->right, node, depth + 1, x, y);
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        dfs(root, nullptr, 0, x, y);

        auto node_x = res[0];
        auto node_y = res[1];

        return node_x.first != node_y.first and node_x.second == node_y.second;
    }
};