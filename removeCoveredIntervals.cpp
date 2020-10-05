class Solution
{
public:
    static bool comp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        vector<vector<int>> sol;

        sort(intervals.begin(), intervals.end(), comp);

        for (auto &x : intervals)
        {
            if (sol.empty())
            {
                sol.emplace_back(x);
                continue;
            }

            if (sol.back()[0] <= x[0] and x[1] <= sol.back()[1])
                continue;

            sol.emplace_back(x);
        }

        return sol.size();
    }
};

// OR

class Solution
{
public:
    static bool comp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        vector<vector<int>> sol;

        sort(intervals.begin(), intervals.end(), comp);

        int count = 0;
        vector<int> cur;

        for (auto &x : intervals)
        {
            if (cur.empty())
            {
                cur = x;
                count++;
                continue;
            }

            if (cur[0] <= x[0] and x[1] <= cur[1])
                continue;

            cur = x;
            count++;
        }

        return count;
    }
};