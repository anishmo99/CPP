class Solution
{
public:
    int binarySearch(vector<int> arr, int low, int high, int key)
    {
        if (high < low)
            return -1;
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        if (key > arr[mid])
            return binarySearch(arr, mid + 1, high, key);
        return binarySearch(arr, low, mid - 1, key);
    }

    int findPivot(vector<int> arr, int low, int high)
    {
        if (high < low)
            return -1;
        int mid = (high + low) / 2;
        if (mid < high && arr[mid] > arr[mid + 1])
            return mid;
        if (mid > low && arr[mid] < arr[mid - 1])
            return mid - 1;
        if (arr[low] >= arr[mid])
            return findPivot(arr, low, mid - 1);
        return findPivot(arr, mid + 1, high);
    }

    int pivotBS(vector<int> arr, int n, int key)
    {
        int pivot = findPivot(arr, 0, n - 1);

        if (pivot == -1)
            return binarySearch(arr, 0, n - 1, key);

        if (arr[pivot] == key)
            return pivot;

        if (arr[0] <= key)
            return binarySearch(arr, 0, pivot - 1, key);
        return binarySearch(arr, pivot + 1, n - 1, key);
    }

    int search(vector<int> &nums, int target)
    {
        return pivotBS(nums, nums.size(), target);
    }
};

// fastest solution

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (nums[high] >= target && nums[mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};