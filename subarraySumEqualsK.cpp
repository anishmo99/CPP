class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> ump;
        int sum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == k)
                count++;
            if (ump.find(sum - k) != ump.end())
                count += ump[sum - k];
            ump[sum]++;
        }
        return count;
    }
};