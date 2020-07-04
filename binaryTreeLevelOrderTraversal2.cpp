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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> current_level;
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp != nullptr)
                {
                    current_level.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            if (current_level.size() > 0)
                result.emplace_back(current_level);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};