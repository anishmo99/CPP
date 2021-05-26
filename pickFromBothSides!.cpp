int Solution::solve(vector<int> &A, int B) {
	int sum = 0;
    int	n = A.size();

    for(int i = 0; i < B; i++)
        sum += A[i];
    
    int ans = sum;
    for(int i = 0; i < B; i++){
        sum = sum - A[B - 1 - i] + A[n - 1 - i];
        ans = max(ans, sum);
    }

	return ans;	
}
