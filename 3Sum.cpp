class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int l = i + 1;
            int r = n - 1;
            int tar = -nums[i];
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (sum < tar)
                {
                    l++;
                }
                else if (sum > tar)
                {
                    r--;
                }
                else
                {
                    vector<int> trip(3);
                    trip[0] = nums[i];
                    trip[1] = nums[l];
                    trip[2] = nums[r];
                    ans.push_back(trip);
                    while (l < r && nums[l] == trip[1])
                    {
                        l++;
                    }
                    while (r > l && nums[r] == trip[2])
                    {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};