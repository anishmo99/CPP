class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;

        for (int x : nums)
            pq.push(x);

        int res;
        while (k--)
        {
            res = pq.top();
            pq.pop();
        }

        return res;
    }
};