class Solution
{
public:
    int findPivot(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (high > low)
        {
            int mid = low + (high - low) / 2;
            if (mid < high && nums[mid] > nums[mid + 1])
                return mid + 1;
            else if (mid > low && nums[mid - 1] > nums[mid])
                return mid;
            else if (nums[low] < nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 0;
    }
    int findMin(vector<int> &nums)
    {
        int pivot = findPivot(nums);
        return nums[pivot];
    }
};

// fastest solution

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int i;
        for (i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                return nums[i + 1];
        }
        return nums[0];
    }
};