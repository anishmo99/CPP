class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// memoization
class Solution
{
public:
    vector<vector<int>> dp;
    int fun(vector<int> &arr, int sum, int n)
    {
        if (n <= 0)
            return INT_MAX - 1;

        if (sum == 0)
            return 0;

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (arr[n - 1] <= sum)
            return dp[n][sum] = min(1 + fun(arr, sum - arr[n - 1], n), fun(arr, sum, n - 1));
        else
            return dp[n][sum] = fun(arr, sum, n - 1);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        dp.resize(n + 1, vector<int>(amount + 1, -1));

        int ans = fun(coins, amount, n);
        return ans == INT_MAX - 1 ? -1 : ans;
    }
};