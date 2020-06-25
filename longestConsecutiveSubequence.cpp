// function to find longest consecutive subsequence
// n : size of array
// arr[] : input array
int findLongestConseqSubseq(int arr[], int n)
{
    sort(arr, arr + n);
    int max_count = 1, count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] + 1 == arr[i + 1])
            count++;
        else if (arr[i] == arr[i + 1])
            continue;
        else
            count = 1;
        max_count = max(max_count, count);
    }
    return max_count;
}