class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string& s1, string& s2, int m, int n){
        if(m == 0 or n == 0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(s1[m - 1] == s2[n - 1])
            return dp[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
        
        return dp[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
        
    }
    int minInsertions(string s) {
        dp.clear();
        dp.resize(s.size() + 1, vector<int> (s.size() + 1, -1));
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        return s.length() - lcs(s, rev, s.size(), s.size());
    }
};