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

// OR

class Solution
{
public:
    // refer - https://www.youtube.com/watch?v=ojz8xZc8pog&ab_channel=thecodingworld

    int countSquares(vector<vector<int>> &matrix)
    {

        int row = matrix.size();
        int col = matrix[0].size();

        int sum = 0;

        vector<vector<int>> v(row + 1, vector<int>(col + 1, 0));

        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++)
            {
                if (matrix[i - 1][j - 1] == 1)
                {
                    v[i][j] = 1 + min(v[i - 1][j], min(v[i][j - 1], v[i - 1][j - 1]));
                    sum += v[i][j];
                }
            }

        return sum;
    }
};