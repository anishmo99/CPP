class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() == 0)
            return ans;

        sort(nums.begin(), nums.end());

        vector<int> sub;
        subset(nums, ans, sub, 0);
        return ans;
    }
    void subset(vector<int> &nums, vector<vector<int>> &ans, vector<int> sub, int start)
    {
        ans.push_back(sub);
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start and nums[i] == nums[i - 1])
                continue;
            sub.push_back(nums[i]);
            subset(nums, ans, sub, i + 1);
            sub.pop_back();
        }
    }
};

// or

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() == 0)
            return ans;

        sort(nums.begin(), nums.end());

        vector<int> sub;
        subset(nums, ans, sub, 0);
        return ans;
    }
    void subset(vector<int> &nums, vector<vector<int>> &ans, vector<int> sub, int start)
    {
        bool flag = false;
        for (auto a : ans)
            if (a == sub)
                flag = true;

        if (!flag)
            ans.push_back(sub);

        for (int i = start; i < nums.size(); i++)
        {
            sub.push_back(nums[i]);
            subset(nums, ans, sub, i + 1);
            sub.pop_back();
        }
    }
};