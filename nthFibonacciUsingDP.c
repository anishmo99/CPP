

#include <stdio.h>

int main() {
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        int fib[n+2];
        fib[0]=0;
        fib[1]=1;
        for(int i=2;i<=n;i++)
        {
            fib[i]=fib[i-1]%1000000007+fib[i-2]%1000000007;
        }
        printf("%d\n",fib[n]%1000000007);
    }
	return 0;
}