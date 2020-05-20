#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumIncreasingSubsequence(int arr[],int n)
{
    int msis[n];
    for(int i=0;i<n;i++)
        msis[i]=arr[i];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&msis[i]<msis[j]+arr[i])
                msis[i]=msis[j]+arr[i];
        }
    }
    return *max_element(msis,msis+n);
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
        printf("%d\n",maxSumIncreasingSubsequence(arr,n));
    }
    return 0;
}


