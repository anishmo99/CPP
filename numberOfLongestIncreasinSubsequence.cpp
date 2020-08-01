class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        vector<int> dp(nums.size(), 1), count(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i] == dp[j])
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[i] == dp[j] + 1)
                    {
                        count[i] += count[j];
                    }
                }
            }
        }

        int sum = 0;
        int max = *max_element(dp.begin(), dp.end());

        for (int i = 0; i < dp.size(); i++)
        {
            if (dp[i] == max)
            {
                sum += count[i];
            }
        }
        return sum;
    }
};