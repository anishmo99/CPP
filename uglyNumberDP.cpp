#include <iostream>
#include <algorithm>

using namespace std;

long getUgly(int n)
{
    long ugly[n];
    ugly[0]=1;
    long nextUgly=1;
    long i2=0,i3=0,i5=0;
    long nextMul2=2,nextMul3=3,nextMul5=5;
    for(int i=1;i<n;i++)
    {
        nextUgly=min(nextMul2,min(nextMul3,nextMul5));
        ugly[i]=nextUgly;
        if(nextUgly==nextMul2)
            nextMul2=ugly[++i2]*2;
        if(nextUgly==nextMul3)
            nextMul3=ugly[++i3]*3;
        if(nextUgly==nextMul5)
            nextMul5=ugly[++i5]*5;
    }
    return nextUgly;
}

int main(int argc, char const *argv[])
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        cout<<getUgly(n)<<endl;
    }
    return 0;
}
