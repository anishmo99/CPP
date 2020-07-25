class MedianFinder
{
public:
    /** initialize your data structure here. */

    priority_queue<int> lower;                             // max_heap for lower half elements
    priority_queue<int, vector<int>, greater<int>> higher; // min_heap for upper half elements
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        lower.push(num);

        higher.push(lower.top());
        lower.pop();

        if (lower.size() < higher.size())
        {
            lower.push(higher.top());
            higher.pop();
        }
    }

    double findMedian()
    {
        return lower.size() > higher.size() ? lower.top() : (double)(lower.top() + higher.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */