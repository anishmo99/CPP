class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);

        dp[0] = dp[1] = 1;

        // loop for number of keys (ith loop)
        for (int i = 2; i <= n; i++)
        {
            // loop for number of combinations (jth loop)
            for (int j = 0; j < i; j++)
            {
                // [number of keys to the left * number of keys to the right
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};
// catalan number concept