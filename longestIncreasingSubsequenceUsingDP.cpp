#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(int arr[],int n)
{
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    return *max_element(lis,lis+n);
}

int main(int argc, char const *argv[])
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        printf("%d\n",LIS(arr,n));
    }
    return 0;
}


