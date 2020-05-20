#include <stdio.h>

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
        int first=1001,second=1001;
        for(int i=0;i<n;i++)
        {
            if(first>arr[i])
            {
                second=first;
                first=arr[i];
            }
            else if(arr[i]<second&&arr[i]!=first)
                second=arr[i];
        }
        if(second==1001)
        printf("-1\n");
        else
        printf("%d %d\n",first,second);
    }
    return 0;
}
