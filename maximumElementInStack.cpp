#include <bits/stdc++.h>
using namespace std;


int main() {
    stack<long long int>s;
    int queries;
    long long int max_element=LONG_LONG_MIN;
    cin>>queries;
    while(queries--)
    {
        int q;
        
        cin>>q;
        if(q==1)
        {
            long long int data;
            cin>>data;
            s.push(data);
            max_element=max(max_element,s.top());
            s.push(max_element);
        }
        else if(q==2)
        {
            s.pop(); // pop max in stack
            s.pop(); // pop data at top
            if(!s.empty())
                max_element=s.top();
            else 
                max_element=LONG_LONG_MIN;
        }
        else if(q==3)
        {
            if(!s.empty())
                cout<<s.top()<<endl;
        }
    }
    return 0;
}
