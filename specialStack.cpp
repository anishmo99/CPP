#include <iostream>
#include <stack>
#include <limits.h>

void push(int a)
{
     s.push(a);
}

bool isFull(int n)
{
    if(s.size()==n)
        return true;
    return false;
}

bool isEmpty()
{
    if(!s.size())
        return true;
    return false;
}

int pop()
{
    int x=s.top();
    s.pop();
    return x;
}

int getMin()
{
    int min=INT_MAX;
    while(!s.empty())
    {
        if(s.top()<min)
            min=s.top();
        s.pop();
    }
    return min;
}