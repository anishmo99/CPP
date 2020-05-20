#include <iostream>
using namespace std;

void printDuplicates(int a[],int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        int index=a[i]%n;
        a[index]+=n;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]/n>1)
        {
            cout<<i<<" ";
            flag=1;
        }
    }
    if(flag==0)
        cout<<-1;
}

