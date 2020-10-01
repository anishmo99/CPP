class MinStack
{
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> stack;
    int min = INT_MAX;

    MinStack()
    {
    }

    void push(int x)
    {
        if (stack.empty())
        {
            stack.push(make_pair(x, x));
            return;
        }

        int min = stack.top().second < x ? stack.top().second : x;
        stack.push(make_pair(x, min));
    }

    void pop()
    {
        stack.pop();
    }

    int top()
    {
        return stack.top().first;
    }

    int getMin()
    {
        return stack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */