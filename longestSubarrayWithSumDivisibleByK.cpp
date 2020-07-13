#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        int k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int hash[k]; // stores all the mod of values (sum[0]%k+......+sum[i]%k)
        memset(hash, 0, sizeof(hash));
        hash[0]++;

        int s = 0, max_count = 0;

        for (int i = 0; i < n; i++)
        {
            s = ((s + arr[i]) % k + k) % k;
            hash[i] = s;
        }

        unordered_map<int, int> ump;
        for (int i = 0; i < n; i++)
        {
            if (hash[i] == 0)
                max_count = i + 1;
            else if (ump.find(hash[i]) == ump.end())
                ump[hash[i]] = i;
            else if (max_count < (i - ump[hash[i]]))
            {
                max_count = i - ump[hash[i]];
            }
        }
        cout << max_count << endl;
    }
    return 0;
}


// or without using hash array

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        int k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int s = 0, max_count = 0;

        int mod_sum = 0;
        unordered_map<int, int> ump;
        for (int i = 0; i < n; i++)
        {
            mod_sum = ((mod_sum + arr[i]) % k + k) % k;
            if (mod_sum == 0)
                max_count = i + 1;
            else if (ump.find(mod_sum) == ump.end())
                ump[mod_sum] = i;
            else if (max_count < (i - ump[mod_sum]))
            {
                max_count = i - ump[mod_sum];
            }
        }
        cout << max_count << endl;
    }
    return 0;
}