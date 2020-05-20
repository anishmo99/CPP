#include <iostream>
#include <stack>

using namespace std;

class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};

/*returns min element from stack*/

int _stack :: getMin()
{
    if(s.empty())
        return -1;
    return s.top();
}

/*returns poped element from stack*/
int _stack ::pop()
{
    int x;
    if(s.empty())   return -1;
    else
    {
        s.pop(); //minEle
        x=s.top();
        s.pop();
        if(!s.empty())
            minEle=s.top();
        return x; //popped element
    }
}