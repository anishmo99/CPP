class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        map<int, int> map;
        int sum = 0, count = 0;
        map[0]++;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (map.find(sum - k) != map.end())
                count += map[sum - k];
            map[sum]++;
        }
        return count;
    }
};