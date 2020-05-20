
#include <stdio.h>
#include <math.h>

int sumOfDigits(int sum)
{
    if (sum==0)
        return 0;
    else if(sum>0&&sum<10)
        return sum;
    else
        return sumOfDigits(sum%10+sumOfDigits(sum/10));
}

int main()
{
    int p,q,num=0,sum=0;
    scanf("%d %d",&p,&q);
    for(int i=0;i<q;i++)
    {
        num=num*pow(10,q)+p;
    }
    printf("%d\n",sumOfDigits(num));
}
