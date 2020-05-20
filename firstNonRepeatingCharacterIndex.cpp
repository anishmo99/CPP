#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int firstUniqChar(string s)
{
    int count[26]={0};
    queue<char> q;
    for(int i=0;i<s.length();i++)
    {
        q.push(s[i]);
        count[s[i]-'a']++;
        while(!q.empty())
        {
            if(count[q.front()-'a']>1)
                q.pop();
            else
                break;
        }
    }
    return s.find(q.front());
}

