class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int cur_count = 0, max_count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                cur_count++;
                max_count = max(max_count, cur_count);
            }
            else
            {
                cur_count = 0;
            }
        }

        return max_count;
    }
};