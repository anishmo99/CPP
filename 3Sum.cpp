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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < int(nums.size()) - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int sum = 0 - nums[i];
                int low = i + 1;
                int high = nums.size() - 1;

                while (low < high)
                {
                    if (nums[low] + nums[high] == sum)
                    {
                        ans.push_back(vector<int>{nums[i], nums[low], nums[high]});
                        while (low < high && nums[low] == nums[low + 1])
                            low++;
                        while (low < high && nums[high] == nums[high - 1])
                            high--;

                        low++;
                        high--;
                    }
                    else if (nums[low] + nums[high] > sum)
                        high--;
                    else
                        low++;
                }
            }
        }
        return ans;
    }
};