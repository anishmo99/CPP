#include <iostream>
using namespace std;

int maxDiv(int a,int b)
{
    while(a%b==0)
        a/=b;
    return a;
}

int isUgly(int num)
{
    num=maxDiv(num,2);
    num=maxDiv(num,3);
    num=maxDiv(num,5);
    return num==1?1:0;
}

int getUgly(int n)
{
    int i=1,count=1;
    while(n>count)
    {
        if(isUgly(++i))
            count++;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    printf("%d",getUgly(n));
    return 0;
}
