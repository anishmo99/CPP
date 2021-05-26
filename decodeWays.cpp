class Solution {
public:
    vector<int> dp;
    int solve(string& s, int i, int n){
        if(i >= n)
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        if(s[i] == '0')
            return dp[i] = 0;
        
        int onedig = solve(s, i + 1, n);
        
        int twodig = 0;
        
        if(i < n - 1 and (s[i] == '1' or (s[i] == '2' and s[i + 1] <= '6')))
            twodig = solve(s, i + 2, n);
        
        return dp[i] = onedig + twodig;
    }
    int numDecodings(string s) {
        dp.assign(s.size(), -1);
        
        return solve(s, 0, s.size());
    }
};