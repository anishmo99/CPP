#include <stdio.h>
#include <stdbool.h>

bool keyPair(int arr[],int n,int sum)
{
    bool s[100000]={0};
    int temp;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        temp=sum-arr[i];
        if(temp>0&&s[temp]==1)
            return 1;
        s[arr[i]]=1;
    }
    return 0;
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
	    int n, sum;
	    scanf("%d %d",&n,&sum);
	   int arr[n];
	   for(int i=0;i<n;i++)
	   {
	       scanf("%d",&arr[i]);
	   }
	   if(keyPair(arr,n,sum)==1)
	   {
	       printf("Yes\n");
	   }
	   else
	   {
	       printf("No\n");
	   }
	}
	return 0;
}