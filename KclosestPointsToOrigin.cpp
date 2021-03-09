class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<pair<int, pair<int, int>>> val;

        for (vector x : points)
        {
            int dist = pow(x[0], 2) + pow(x[1], 2);
            val.push_back({dist, {x[0], x[1]}});
        }

        sort(val.begin(), val.end());

        vector<vector<int>> ans(k);

        for (int i = 0; i < k; i++)
        {
            ans[i].push_back(val[i].second.first);
            ans[i].push_back(val[i].second.second);
        }

        return ans;
    }
};

// heap

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        priority_queue<pair<int, pair<int, int>>> maxheap;

        for (auto x : points)
        {
            maxheap.push({x[0] * x[0] + x[1] * x[1], {x[0], x[1]}});

            if (maxheap.size() > K)
                maxheap.pop();
        }

        vector<vector<int>> ans;
        while (maxheap.size() > 0)
        {
            int x = maxheap.top().second.first;
            int y = maxheap.top().second.second;
            ans.push_back({x, y});
            maxheap.pop();
        }

        return ans;
    }
};