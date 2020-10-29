class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jumps = 0, curend = 0, curfurthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curfurthest = max(curfurthest, i + nums[i]);
            if (i == curend)
            {
                jumps++;
                curend = curfurthest;
            }
        }
        return jumps;
    }
};