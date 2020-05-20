#include <iostream>
#include <stack>

using namespace std;

void reverse(char *str, int len)
{
    stack <char> s;
    for(int i=0;i<len;i++)
    {
        s.push(str[i]);
    }
    for(int i=0;i<len;i++)
    {
        str[i]=s.top();
        s.pop();
    }
}

/*
void reverse(char *str,int len)
{
    stack<char> s;
    for(int i=0;i<len;i++)
    {
        s.push(str[i]);
    }
    int i=0;
    while(!s.empty())
    {
        str[i]=s.top();
        s.pop();
        i++;
    }
}
*/