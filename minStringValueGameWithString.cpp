#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int MinStringValue(string s,int k)
{
    if(s.length()<=k)   return 0;
    
    int frequency[26]={0};
    
    for(int i=0;i<s.length();i++)
        frequency[s[i]-'a']++;
    
    priority_queue<int> q;
    
    for(int i=0;i<26;i++)
        q.push(frequency[i]);
   
    while(k--)
    {
        int temp=q.top();
        q.pop();
        q.push(--temp);
    }
    
    int sum=0;
    while(!q.empty())
    {
        int temp=q.top();
        sum+=temp*temp;
        q.pop();
    }
    
    return sum;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        string s;
        int k;
        cin>>s>>k;
        cout<<MinStringValue(s,k)<<endl;
    }
    return 0;
}
