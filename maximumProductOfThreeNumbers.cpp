// O(log(N))

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[n - 1] * nums[0] * nums[1]);
    }
};

// O(N)

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int max_a = INT_MIN, max_b = INT_MIN, max_c = INT_MIN;
        int min_a = INT_MAX, min_b = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max_a)
            {
                max_c = max_b;
                max_b = max_a;
                max_a = nums[i];
            }
            else if (nums[i] > max_b)
            {
                max_c = max_b;
                max_b = nums[i];
            }
            else if (nums[i] > max_c)
            {
                max_c = nums[i];
            }
            if (nums[i] < min_a)
            {
                min_b = min_a;
                min_a = nums[i];
            }
            else if (nums[i] < min_b)
            {
                min_b = nums[i];
            }
        }
        return max(max_a * max_b * max_c, max_a * min_a * min_b);
    }
};