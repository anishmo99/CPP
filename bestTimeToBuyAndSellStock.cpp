class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;
        int min = INT_MAX;
        for (int i{}; i < prices.size(); i++)
        {
            if (prices[i] < min)
                min = prices[i];
            else if (prices[i] - min > max_profit)
                max_profit = prices[i] - min;
        }
        return max_profit;
    }
};