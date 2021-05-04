vector<vector<int>> dp;
int solve(string& a, string& b, int m, int n){
	if(m <= 0 or n <= 0)
		return 0;

	if(dp[m][n] != -1)
		return dp[m][n];

	if(a[m - 1] == b[n - 1] and m != n)
		return dp[m][n] = 1 + solve(a, b, m - 1, n - 1);

	return dp[m][n] = max(solve(a, b, m - 1, n), solve(a, b, m, n - 1));
}

int Solution::anytwo(string A) {
	dp.clear();
	dp.resize(A.size() + 1, vector<int> (A.size() + 1, -1));
	return solve(A, A, A.size(), A.size()) >= 2 ? 1 : 0;
}
