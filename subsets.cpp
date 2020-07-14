class Solution
{
public:
    void subsetsUtil(vector<int> &A, vector<vector<int>> &res, vector<int> &subset, int index)
    {
        res.push_back(subset);
        for (int i = index; i < A.size(); i++)
        {

            // include the A[i] in subset.
            subset.push_back(A[i]);

            // move onto the next element.
            subsetsUtil(A, res, subset, i + 1);

            // exclude the A[i] from subset and triggers
            // backtracking.
            subset.pop_back();
        }

        return;
    }

    vector<vector<int>> subsets(vector<int> &A)
    {
        vector<int> subset;
        vector<vector<int>> res;

        // keeps track of current element in vector A;
        int index = 0;
        subsetsUtil(A, res, subset, index);

        return res;
    }
};

// fastest

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() == 0)
            return ans;
        sort(nums.begin(), nums.end());
        vector<int> sub;
        subset(nums, ans, sub, 0);
        return ans;
    }
    void subset(vector<int> &nums, vector<vector<int>> &ans, vector<int> sub, int start)
    {
        ans.push_back(sub);
        for (int i = start; i < nums.size(); i++)
        {
            sub.push_back(nums[i]);
            subset(nums, ans, sub, i + 1);
            sub.pop_back();
        }
    }
};

// GFG

#include <bits/stdc++.h>
using namespace std;

void subset(vector<int> &arr, vector<vector<int>> &res, vector<int> &r, int start)
{
    res.push_back(r);
    for (int i = start; i < arr.size(); i++)
    {
        r.push_back(arr[i]);
        subset(arr, res, r, i + 1);
        r.pop_back();
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        int i;
        for (i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            arr.push_back(c);
        }
        vector<vector<int>> res;
        vector<int> r;

        sort(arr.begin(), arr.end());

        subset(arr, res, r, 0);

        set<vector<int>> ss;
        for (i = 0; i < res.size(); i++)
        {
            ss.insert(res[i]);
        }

        for (auto it = ss.begin(); it != ss.end(); it++)
        {
            vector<int> ans = (*it);
            int j = 0;
            cout << "(";
            for (j = 0; j < ans.size(); j++)
            {
                if (j == ans.size() - 1)
                    cout << ans[j];
                else
                    cout << ans[j] << " ";
            }
            cout << ")";
        }
        cout << endl;
    }
    return 0;
}