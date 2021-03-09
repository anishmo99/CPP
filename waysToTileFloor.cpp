class Solution
{
public:
    long long numberOfWays(long long N)
    {
        vector<long long> dp(N + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (long long i = 2; i <= N; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }

        return dp[N];
    }
};

// OR

class Soultion
{
public:
    vector<long long> dp;

    long long fun(long long n)
    {
        if (dp[n] != 0)
            return dp[n];
        return dp[n] = (fun(n - 1) + fun(n - 2)) % 1000000007;
    }

    long long numberOfWays(long long N)
    {
        dp.resize(N + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        return fun(N) % 1000000007;
    }
};