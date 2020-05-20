#include <stdio.h>

int min(int a, int b) {  return a<b?a:b; }

int main() {
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        if(n<r)
            printf("0\n");
        else
        {
            int C[n+1][r+1];
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=min(n,r);j++)
                {
                    if(i==j||j==0)
                        C[i][j]=1;
                    else
                    {
                        C[i][j]=C[i-1][j-1]%1000000007+C[i-1][j]%1000000007;
                    }
                }
            }
            printf("%d\n",C[n][r]%1000000007);
        }
    }
	return 0;
}