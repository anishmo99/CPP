class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool> (s.size(), false));
        
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            dp[i][i] = true;
        }
        
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i + 1])
                dp[i][i + 1] = true;
        }
        
        for(int k = 3; k <= s.size(); k++){
            for(int i = 0; i <= s.size() - k; i++){
                int j = i + k - 1;
                
                if(s[i] == s[j] and dp[i + 1][j - 1])
                    dp[i][j] = true;
            }
        }
        
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < s.size(); j++){
                if(dp[i][j])
                    count++;
            }
        }
        
        return count;
    }
};