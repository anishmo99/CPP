#include <iostream>
#include <stack>

using namespace std;

bool balanced(string exp)
{
    stack<char> s;
    char x;
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        {
           s.push(exp[i]);
           continue;
        }

        if(s.empty())
            return false;

        switch(exp[i])
        {
            case ')':
            {
                x=s.top();
                s.pop();
                if(x=='{'||x=='[')
                    return false;
                break;
            }
            case '}':
            {
                x=s.top();
                s.pop();
                if(x=='('||x=='[')
                    return false;
                break;
            }
            case ']':
            {

                x=s.top();
                s.pop();
                if(x=='('||x=='{')
                    return false;
                break;
            }
        }
    }
    return s.empty();
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        string exp;
        cin>>exp;
        if(balanced(exp))
            cout<<"balanced"<<endl;
        else
            cout<<"not balanced"<<endl;
    }
}
