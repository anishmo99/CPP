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

// better

class Solution
{
public:
    void generateCombinations(int i, int k, vector<int> &a, vector<int> &tmp, vector<vector<int>> &res)
    {
        if (i == a.size())
        {
            tmp.pop_back();
            return;
        }
        if (k < 0)
        {
            tmp.pop_back();
            return;
        }
        if (k == 0)
        {
            res.push_back(tmp);
            tmp.pop_back();
        }
        else
        {
            tmp.push_back(a[i]);
            generateCombinations(i, k - a[i], a, tmp, res);
            generateCombinations(i + 1, k, a, tmp, res);
        }
    }
    vector<vector<int>> combinationSum(vector<int> &s, int k)
    {
        vector<int> tmp;
        vector<vector<int>> res;
        generateCombinations(0, k, s, tmp, res);
        return res;
    }
};