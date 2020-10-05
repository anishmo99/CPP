class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;

        vector<int> maxl(height.size(), 0), maxr(height.size(), 0), water(height.size(), 0);

        maxl[0] = height[0];
        for (int i = 1; i < height.size(); i++)
        {
            maxl[i] = max(maxl[i - 1], height[i]);
        }

        maxr[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--)
        {
            maxr[i] = max(maxr[i + 1], height[i]);
        }

        for (int i = 0; i < height.size(); i++)
        {
            water[i] = min(maxl[i], maxr[i]) - height[i];
        }

        return accumulate(water.begin(), water.end(), 0);
    }
};