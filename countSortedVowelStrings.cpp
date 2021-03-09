class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        // u o i e a
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < 5; j++){
                dp[j] += sum;
                sum = dp[j];
            }
        }
        return dp.back();
    }
};