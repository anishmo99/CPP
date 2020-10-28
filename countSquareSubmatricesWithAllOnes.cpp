class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int r = matrix.size(), c = matrix[0].size();

        vector<vector<int>> dp(r, vector<int>(c, 0));

        for (int i = 0; i < c; i++)
        {
            if (matrix[0][i] == 1)
                dp[0][i] = 1;
        }

        for (int i = 0; i < r; i++)
        {
            if (matrix[i][0] == 1)
                dp[i][0] = 1;
        }

        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                if (matrix[i][j] == 1)
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                while (dp[i][j] >= 1)
                {
                    count++;
                    dp[i][j]--;
                }
            }
        }
        return count;
    }
};