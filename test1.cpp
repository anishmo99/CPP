int isPowerOfTwo(int n) {
        if(n==1)
        return 1;
        if(n<=0)    return false;
        while(n%2==0)
        {
            n/=2;
        }
        if(n==1)
            return 1;
        return 0;
    }


int* isPower(int n,int *arr, int* result_count)
{
    for(int i=0;i<n;i++)
    {
        result.count[i]=isPowerOfTwo(arr[i]);
    }
    return *result_count;
}