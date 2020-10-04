class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            while (low < high and nums[low] == nums[low + 1])
                low++;

            while (high > low and nums[high] == nums[high - 1])
                high--;

            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[mid] > nums[high])
            {
                if (target < nums[mid] and target >= nums[low])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            else if (nums[mid] < nums[low])
            {
                if (target <= nums[high] and target > nums[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            else
            {
                if (target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return false;
    }
};
