#include <stdio.h>

int main() {
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        int count=0;
        while(n)
        {
            if(n%2==0)
                n/=2;
            else
                n-=1;
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
