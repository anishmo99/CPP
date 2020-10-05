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

// BINARY SEARCH

class Solution
{
public:
    TreeNode *func(vector<int> &nums, int low, int high)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            TreeNode *root = new TreeNode(nums[mid], func(nums, low, mid - 1), func(nums, mid + 1, high));

            // TreeNode *root = new TreeNode(nums[mid]);
            // root->left = func(nums, low, mid - 1);
            // root->right = func(nums, mid + 1, high);

            return root;
        }
        return nullptr;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return func(nums, 0, nums.size() - 1);
    }
};

// FASTEST SOLUTION

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() < 1)
            return NULL;
        int mid = (nums.size() / 2);
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};