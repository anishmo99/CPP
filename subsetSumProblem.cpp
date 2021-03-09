class Solution
{
public:
    int equalPartition(int n, int nums[])
    {
        int sum = accumulate(nums, nums + n, 0);

        if (sum % 2 != 0)
            return false;

        sum = sum / 2;

        bool dp[n + 1][sum + 1];

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= sum; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (j < nums[i - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                if (j >= nums[i - 1])
                {
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][sum] ? 1 : 0;
    }
};