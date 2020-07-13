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