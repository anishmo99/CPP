class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        vector<vector<short>> dp(a.size() + 1, vector<short> (b.size() + 1, 0));
        
        for(int i = 1; i <= a.size(); i++) {
            for(int j = 1; j <= b.size(); j++) {
                if(a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
                
            }
        }
        return dp[a.size()][b.size()];
    }
};

// memoization

class Solution
{
public:
    vector<vector<int>> dp;
    int fun(string &x, string &y, int m, int n)
    {
        if (m == 0 or n == 0)
            return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (x[m - 1] == y[n - 1])
            return dp[m][n] = 1 + fun(x, y, m - 1, n - 1);
        else
            return dp[m][n] = max(fun(x, y, m, n - 1), fun(x, y, m - 1, n));
    }
    int longestCommonSubsequence(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();

        dp.clear();
        dp.resize(m + 1, vector<int>(n + 1, -1));

        return fun(s1, s2, m, n);
    }
};