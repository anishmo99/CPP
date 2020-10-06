#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] % 1000000007 + dp[i][j - 1] % 1000000007;
        }
    }

    return dp[m - 1][n - 1] % 1000000007;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int m, n;
        cin >> m >> n;
        cout << uniquePaths(m, n) % 1000000007 << endl;
    }
    return 0;
}