int Solution::solve(vector<int> &A) {
    if(A.size() == 0)
        return 0;
        
    int totalsum = 0;
    
    int n = A.size();
    
    for (int i = 0; i < n; i++)
        totalsum += A[i];

    vector<vector<bool>> dp(A.size() + 1, vector<bool> (totalsum + 1, false));

    for(int i = 0; i < n + 1; i++)
    	dp[i][0] = true;

    for(int i = 1; i < n + 1; i++){
    	for(int j = 1; j < totalsum + 1; j++){
    	    if(A[i - 1] <= j)
    		    dp[i][j] = dp[i - 1][j - A[i - 1]] or dp[i - 1][j];
    		    
    		else if(A[i - 1] > j)
    		    dp[i][j] = dp[i - 1][j];
    	}
    }

    int mindiff = INT_MAX;

    for(int i = 0; i <= totalsum / 2; i++){
    	if(dp[n][i] == true)
    		mindiff = min(mindiff, abs(totalsum - 2 * i));
    }
    
    return mindiff;
}