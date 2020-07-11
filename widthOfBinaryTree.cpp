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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int result = 1;
        while (!q.empty())
        {
            int n = q.size();
            int start = q.front().second;
            int end = q.back().second;
            result = max(result, end - start + 1);
            for (int i = 0; i < n; i++)
            {
                pair<TreeNode *, int> p = q.front();
                int index = p.second - start;
                q.pop();
                if (p.first->left)
                    q.push({p.first->left, 2 * index + 1});
                if (p.first->right)
                    q.push({p.first->right, 2 * index + 2});
            }
        }
        return result;
    }
};