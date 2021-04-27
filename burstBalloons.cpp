class Solution
{
public:
    vector<vector<int>> dp;

    int fun(vector<int> &v, int i, int j)
    {
        if (i > j)
            return 0;

        int ans = 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        for (int k = i; k <= j; k++)
        {
            int temp = fun(v, i, k - 1) + fun(v, k + 1, j) + (v[i - 1] * v[k] * v[j + 1]);
            ans = max(ans, temp);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int> &v)
    {
        v.insert(v.begin(), 1); // to push 1 in front of vector
        v.push_back(1);

        int n = v.size();
        dp.clear();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return fun(v, 1, v.size() - 2);
    }
};