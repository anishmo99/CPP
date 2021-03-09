class Solution
{
public:
    int countFriendsPairings(int n)
    {
        vector<long long int> dp(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            if (i <= 2)
            {
                dp[i] = i;
            }
            else
            {
                dp[i] = (dp[i - 1] % 1000000007 + ((i - 1) % 1000000007 * dp[i - 2]) % 1000000007) % 1000000007;
            }
        }
        return dp[n] % 1000000007;
    }
};