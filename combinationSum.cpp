class Solution
{
    vector<vector<int>> result;

public:
    void dfs(vector<int> &nums, vector<int> temp, int remain, int start)
    {
        if (remain < 0)
            return;

        else if (remain == 0)
            result.emplace_back(temp);

        else
        {
            for (int i = start; i < nums.size(); i++)
            {
                temp.push_back(nums[i]);
                dfs(nums, temp, remain - nums[i], i);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(candidates, vector<int>(), target, 0);
        return result;
    }
};