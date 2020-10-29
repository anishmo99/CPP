class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxc = 0;

        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                maxc = 1;
            }
        }

        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (matrix[0][i] == '1')
            {
                dp[0][i] = 1;
                maxc = 1;
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '1')
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;

                maxc = max(maxc, dp[i][j]);
            }
        }

        return pow(maxc, 2);
    }
};