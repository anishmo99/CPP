// recursion

int knapSack(int W, int wt[], int val[], int n) 
{
    if(n == 0 or W == 0)
    	return 0;

    if(wt[n - 1] > W)
    	return knapSack(W, wt, val, n - 1);

    else
    	return max(knapSack(W, wt, val, n - 1), val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1));
}

// dynamic program || memoization

int dp[1001][1001];

int func(int W, int wt[], int val[],int n){
	if(n == 0 or W == 0)
		return 0;

	if(dp[n - 1][W] != -1)
		return dp[n - 1][W];

	if(wt[n - 1] > W)
		return dp[n - 1][W] = func(W, wt, val, n - 1);

	else
		return dp[n - 1][W] = max(func(W, wt, val, n - 1), val[n - 1] + func(W - wt[n - 1], wt, val, n - 1));
}

int knapSack(int W, int wt[], int val[], int n){
    memset(dp, -1, sizeof(dp));

	return func(W, wt, val, n);
}

// dynamic program || tabulation

int knapSack(int W, int wt[], int val[], int n) 
{ 
   vector<vector<int>> dp(n + 1, vector<int> (W + 1, 0));
   
   for(int i = 0; i <= n; i++){
       for(int w = 0; w <= W; w++){
       	if(i == 0 or w == 0)
       		dp[i][w] = 0;

       	else if(wt[i - 1] > w)
       		dp[i][w] = dp[i - 1][w];
       		
       	else
       		dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
       }
   }
   
   return dp[n][W];
}