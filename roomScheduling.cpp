bool comp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}
int Solution::solve(vector<vector<int>> &A)
{
    sort(A.begin(), A.end(), comp);

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(A[0][1]);

    for (int i = 1; i < A.size(); i++)
    {
        int top = pq.top();
        if (A[i][0] >= top)
        {
            pq.pop();
        }
        pq.push(A[i][1]);
    }
    return pq.size();
}