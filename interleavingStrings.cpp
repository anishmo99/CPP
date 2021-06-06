class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string& a, string& b, string& c, int n, int m){
        if(n == 0 and m == 0)
            return dp[n][m] = 1;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(n > 0 and m > 0 and a[n - 1] == b[m - 1] and a[n - 1] == c[n + m - 1])
            return dp[n][m] = solve(a, b, c, n - 1, m) or solve(a, b, c, n, m - 1);
        
        else if(n > 0 and a[n - 1] == c[n + m - 1])
            return dp[n][m] = solve(a, b, c, n - 1, m);
        
        else if(m > 0 and b[m - 1] == c[n + m - 1])
            return dp[n][m] = solve(a, b, c, n, m - 1);

        return dp[n][m] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        dp.assign(s1.size() + 1, vector<int> (s2.size() + 1, -1));
       return s3.size() == s1.size() + s2.size() and solve(s1, s2, s3, s1.size(), s2.size()); 
    }
};