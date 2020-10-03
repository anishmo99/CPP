#include<stdio.h>
int main()
{
    int array[200],number,x,m=0,term=0;
    printf("Which number do you want to find factorial? :: ");
    scanf("%d",&number);
    for(int i=0; number!=0; i++)
    {
        array[i] = number % 10;
        number = number / 10;
        m++;
    }
    for(int j=1; j<=number; j++)
    {    
        term = 0;
        for(int k=0; k<m; k++)
        {
            x = array[k]*j + term;
            array[k] = x % 10;
            term = x / 10;
        }
        while(term > 0)
        {
            array[m] = term % 10;
            term = term / 10;
            m++;
        }
    }
    for(int a=m-1; a>=0; a--)
        printf("%d",array[a]);
}
