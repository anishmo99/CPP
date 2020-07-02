class Solution
{
public:
    int arrangeCoins(int n)
    {
        int i{};
        while (n >= i)
        {
            n -= i;
            i++;
        }
        return i - 1;
    }
};