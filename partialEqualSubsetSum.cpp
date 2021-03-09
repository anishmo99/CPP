class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
            return false;

        sum = sum / 2;

        bool dp[nums.size() + 1][sum + 1];

        for (int i = 0; i <= nums.size(); i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= sum; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= nums.size(); i++)
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

        return dp[nums.size()][sum];
    }
};

// OR

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % 2)
            return false;
        sum /= 2;
        // vector<bool> dp(sum+1,false);
        bitset<20000> dp = 0;
        dp[0] = 1;
        for (int num : nums)
        {
            for (int i = sum; i >= num; i--)
            {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[sum];
    }
};