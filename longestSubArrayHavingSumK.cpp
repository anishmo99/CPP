int longSubArrayHavingSumK()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i{}; i < n; i++)
        cin >> arr[i];
    map<int, int> map;
    int sum = 0;
    int count = 0;
    for (int i{}; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
            count = i + 1;
        if (map.find(sum) == map.end())
            map[sum] = i;
        if (map.find(sum - k) != map.end())
        {
            count = max(count, i - map[sum - k]);
        }
    }
    return count;
}