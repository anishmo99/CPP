
#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        int x,sum=0;
        for(int i=0;i<n-1;i++)
        {
          cin>>x;
          sum+=x;
        }
        int allsum=n*(n+1)/2;
        cout<<allsum-sum<<endl;
    }
}
