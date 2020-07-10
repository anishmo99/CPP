class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int hash[k];
        memset(hash, 0, sizeof(hash));
        hash[0]++;
        int s = 0, counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s = ((s + nums[i]) % k + k) % k;
            counter += hash[s];
            hash[s]++;
        }
        return counter;
    }
};

// OR

class Solution
{
public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        unordered_map<int, int> ump;
        int cur_sum = 0, count = 0;
        ump[0]++;
        for (int i = 0; i < A.size(); i++)
        {
            cur_sum = ((cur_sum + A[i]) % K + K) % K;
            if (ump.find(cur_sum) != ump.end())
                count += ump[cur_sum];
            ump[cur_sum]++;
        }
        return count;
    }
};


// GFG

#include <iostream>
#include <cstring>
using namespace std;

int subarraysDivByK(int nums[], int n, int k)
{
    int hash[k];
    memset(hash, 0, sizeof(hash));
    hash[0]++;
    int s = 0, counter = 0;
    for (int i = 0; i < n; i++)
    {
        s = ((s + nums[i]) % k + k) % k;
        counter += hash[s];
        hash[s]++;
    }
    return counter;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << subarraysDivByK(arr, n, k) << endl;
    }
    return 0;
}