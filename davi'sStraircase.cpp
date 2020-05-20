#include <iostream>

using namespace std;

// Complete the stepPerms function below.
int stepPerms(int n) {
    //dynamic programming
    int res[n+1];
    res[0]=res[1]=1;
    res[2]=2;
    for(int i=3;i<=n;i++)
    {
        res[i]=res[i-1]+res[i-2]+res[i-3];
    }
    return res[n];
    
    /*recursion
    if(n<=1)
    return 1;
    else if(n==2)
    return 2;
    else
    return stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3);
     */
}

int main()
{
    int s;
    cin >> s;
    while(s--)
    {
        int n;
        cin>>n;
        cout<<stepPerms(n)<<endl;
    }
    return 0;
}
