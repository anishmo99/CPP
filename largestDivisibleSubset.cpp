class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> sol;
        vector<int> dp(nums.size(), 1);
        int maxcount = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    maxcount = max(maxcount, dp[i]);
                }
            }
        }

        int prev = -1;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (dp[i] == maxcount and (prev == -1 or prev % nums[i] == 0))
            {
                sol.push_back(nums[i]);
                prev = nums[i];
                maxcount--;
            }
        }

        return sol;
    }
};