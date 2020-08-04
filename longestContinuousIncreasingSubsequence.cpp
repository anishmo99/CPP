class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int count = 1;
        int ans = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                count++;
            }
            else if (nums[i] <= nums[i - 1])
            {
                count = 1;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};