class Solution {
public:
    vector<vector<int>> dp;
    
    int maxele(vector<int>& arr, int low, int high){
        int maxi = 0;
        for(int i = low;i <= high; i++){
            maxi = max(arr[i], maxi);
        }
        return maxi;
    }
    
    int solve(vector<int>& arr, int i, int j){
        if(i >= j)
            return dp[i][j] = 0;
        
        if(i + 1 == j)
            return dp[i][j] = arr[i] * arr[j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k = i; k < j; k++){
                int maxik = maxele(arr, i, k);
                int maxkj = maxele(arr, k + 1, j);
            
                int temp = solve(arr, i, k) + solve(arr, k + 1, j) + (maxik * maxkj);
                ans = min(ans, temp);
        }
        
        return dp[i][j] = ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int i = 0;
        int j = arr.size() - 1;
        
        dp.assign(j + 1, vector<int> (j + 1, -1));
        
        return solve(arr, i, j);
    }
};