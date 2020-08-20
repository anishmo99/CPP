// Input : arr[] = {1, 2, 3, 4} Output : 15 There are total increasing subsequences
//         {1}, {2}, {3}, {4}, {1, 2}, {1, 3}, {1, 4},
//         {2, 3}, {2, 4}, {3, 4}, {1, 2, 3}, {1, 2, 4},
//         {1, 3, 4}, {2, 3, 4}, {1, 2, 3, 4}

// okay but not accepted for 436 input 

#include <iostream>
#include <vector>
using namespace std;

int countIncSub(vector<int>& arr)
{
    if(arr.empty())
        return 0;
    vector<long long int> dp(arr.size(), 1);
    
    for(int i = 1; i < arr.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                dp[i] += dp[j];
            }
        }
    }
    long long int sum = 0;
    for(auto x : dp)
    {
        sum += x;
    }
    return sum;
}

int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << countIncSub(arr) << endl;
    }
    return 0;
}