class Solution
{
public:
    int minDistance(string s1, string s2)
    {
        int m = s1.length(), n = s2.length();
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)
                    dp[i][j] = j;

                else if (j == 0)
                    dp[i][j] = i;

                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[m][n];
    }
};

// memoization

class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& a, string& b, int m, int n){
        if(m <= 0)
            return dp[m][n] = n;
        
        if(n <= 0)
            return dp[m][n] = m;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(a[m - 1] == b[n - 1])
            return dp[m][n] = solve(a, b, m - 1, n - 1);
        
        return dp[m][n] = 1 + min(solve(a, b, m - 1, n - 1), min(solve(a, b, m - 1, n), solve(a, b, m, n -1)));
    }
    
    int minDistance(string word1, string word2) {
        dp.assign(word1.size() + 1, vector<int> (word2.size() + 1, -1));
        
        return solve(word1, word2, word1.size(), word2.size());
    }
};