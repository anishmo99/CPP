class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& a, string& b, int m, int n){
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(n <= 0)
            return dp[m][n] = 1;
        
        if(m <= 0)
            return dp[m][n] = 0;
        
        if(a[m - 1] == b[n - 1])
            return dp[m][n] = solve(a, b, m - 1, n - 1) + solve(a, b, m - 1, n);
        
        return dp[m][n] = solve(a, b, m - 1, n);
}
        int numDistinct(string s, string t) {
        dp.clear();
        dp.resize(s.size() + 1, vector<int> (t.size() + 1, -1));
            
        return solve(s, t, s.size(), t.size());
    }
};