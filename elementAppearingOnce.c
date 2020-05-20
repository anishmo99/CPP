#include <stdio.h>

int appearOnce(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            i++;
        }
        else return arr[i];
    }
    return arr[n-1];
}

int main() {
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        printf("%d\n",appearOnce(arr,n));
    }
    return 0;
}
