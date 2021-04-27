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
    int res = 0;
    void dfs(TreeNode *root, int sum)
    {
        if (!root->left and !root->right)
        {
            res += sum * 10 + root->val;
            return;
        }

        if (root->left)
            dfs(root->left, sum * 10 + root->val);

        if (root->right)
            dfs(root->right, sum * 10 + root->val);
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root, 0);
        return res;
    }
};

// BFS

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        int sum = 0;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            auto node = q.front();
            q.pop();
            if (!node->left and !node->right)
            {
                sum += node->val;
            }
            if (node->left)
            {
                node->left->val += node->val * 10;
                q.push(node->left);
            }
            if (node->right)
            {
                node->right->val += node->val * 10;
                q.push(node->right);
            }
        }

        return sum;
    }
};