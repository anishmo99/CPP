class Solution
{
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> temp, int remain, int index)
    {
        if (remain < 0)
            return;
        else if (remain == 0)
        {
            ans.emplace_back(temp);
            return;
        }
        else
        {
            for (int i = index; i < nums.size(); i++)
            {
                temp.push_back(nums[i]);
                backtrack(ans, nums, temp, remain - nums[i], i + 1);
                temp.pop_back();
                while (i + 1 < nums.size() and nums[i] == nums[i + 1])
                    i++;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        backtrack(ans, nums, vector<int>(), target, 0);
        return ans;
    }
};