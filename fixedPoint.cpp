// LINEAR SEARCH

class Solution
{
public:
    vector<int> valueEqualToIndex(int arr[], int n)
    {
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == (i + 1))
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

// BINARY SEARCH

class Solution
{
public:
    int binarySearch(int arr[], int low, int high)
    {
        while (high >= low)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == mid)
                return mid;

            if (arr[mid] > mid)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }
    int valueEqualToIndex(int arr[], int n)
    {
        return binarySearch(arr, 0, n - 1);
    }
};