#include<stdio.h>

int SumOfElement(int *A,int size)
{
    int sum=0;
    for(int i=0; i<size; i++)
        sum += *(A+i);
    return sum;
}

int main()
{
    int A[] = {7,5,3,9,6,1,4};
    int size = sizeof(A)/sizeof(A[0]);
    int s = SumOfElement(A,size);
    printf("Sum is : %d",s);
}
