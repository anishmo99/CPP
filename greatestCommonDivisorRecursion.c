#include<stdio.h>

int GCD(int num1, int num2)
{
    if(num1==num2)
        return num1;
    else if(num1%num2==0)
        return num2;
    else if(num2%num1==0)
        return num1;
    else if(num1>num2)
        GCD(num1%num2,num2);
    else 
        GCD(num1,num2%num1);
}

int main()
{
    printf("%d",GCD(105,91));
}
