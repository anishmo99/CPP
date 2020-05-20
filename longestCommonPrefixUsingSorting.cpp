#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

string LCP(string ar[],int n)
{
    if(n==0)    return "";
    if(n==1)    return ar[0];
    sort(ar,ar+n);
    int minimum=min(ar[0].size(),ar[n-1].size());
    string first=ar[0];
    string last=ar[n-1];
    int i=0,flag=0;
    while(i<minimum&&first[i]==last[i])
    {
        i++;
        flag=1;
    }
    if(flag==0) return "-1";
    return first.substr(0,i);


}

int main(int argc, char const *argv[])
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        cin>>n;
        string ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        cout<<LCP(ar,n)<<endl;
    }
    return 0;
}
