vector<double> runningMedian(vector<int> a)
{
    vector<double> vmedian;
    priority_queue<double> lower;                                   // max_heap of lower half elements
    priority_queue<double, vector<double>, greater<double>> higher; // min_heap of upper half elements

    double median = a[0];
    vmedian.push_back(median);
    lower.push(a[0]);

    for (int i = 1; i < a.size(); i++)
    {
        int number = a[i];
        if (lower.size() > higher.size())
        {
            if (number < median)
            {
                higher.push(lower.top());
                lower.pop();
                lower.push(number);
            }
            else
            {
                higher.push(number);
            }
            median = (lower.top() + higher.top()) / 2;
        }
        else if (lower.size() == higher.size())
        {
            if (number < median)
            {
                lower.push(number);
                median = (double)lower.top();
            }
            else
            {
                higher.push(number);
                median = (double)higher.top();
            }
        }
        else
        {
            if (number > median)
            {
                lower.push(higher.top());
                higher.pop();
                higher.push(number);
            }
            else
            {
                lower.push(number);
            }
            median = (lower.top() + higher.top()) / 2;
        }
        vmedian.push_back(median);
    }
    return vmedian;
}