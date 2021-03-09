class Solution
{
public:
    int maxGold(vector<vector<int>> gold)
    {
        vector<vector<int>> goldDP(gold.size(), vector<int>(gold[0].size()));

        for (int col = gold[0].size() - 1; col >= 0; col--)
        {
            for (int row = 0; row < gold.size(); row++)
            {
                int right = (col == gold[0].size() - 1) ? 0 : goldDP[row][col + 1];

                int right_up = (row == 0 or col == gold[0].size() - 1) ? 0 : goldDP[row - 1][col + 1];

                int right_down = (row == gold.size() - 1 or col == gold[0].size() - 1) ? 0 : goldDP[row + 1][col + 1];

                goldDP[row][col] = gold[row][col] + max(right, max(right_up, right_down));
            }
        }

        int result = goldDP[0][0];

        for (int i = 1; i < gold.size(); i++)
            result = max(result, goldDP[i][0]);

        return result;
    }
}