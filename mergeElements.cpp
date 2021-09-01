#include <numeric>

int fun(vector<int> &A, int i, int j, vector<vector<int>> &dp){
   if(i >= j)
    return dp[i][j] = 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    int sum = 0;
    for(int len = i; len <= j; len++)
        sum += A[len];

    for(int k = i; k < j; k++){
        int temp = sum + fun(A, i, k, dp) + fun(A, k + 1, j, dp);
        ans = min(temp, ans);
    }

    return dp[i][j] = ans; 
}
int Solution::solve(vector<int> &A) {
    vector<vector<int>> dp(A.size(), vector<int> (A.size(), -1));
    return fun(A, 0, A.size() - 1, dp);
}
