class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int left = 0, count = INT_MAX;
        int sum = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];

            while (sum >= s)
            {
                count = min(count, right - left + 1);
                sum -= nums[left++];
            }
        }

        return count == INT_MAX ? 0 : count;
    }
};