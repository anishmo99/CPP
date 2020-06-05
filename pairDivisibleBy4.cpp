#include<iostream>
using namespace std;
int main()
 {
int t;
cin >> t;
while(t--)
{
    int n;
    cin >> n;
    int ar[n];
    for(int i=0;i<n;i++)
    cin >> ar[i];
    
    int count = 0;
    
    int hash[4] = {0};
    for(int i=0;i<n;i++)
    {
        int rem = ar[i]%4;
        if(rem)
        {
            count+=hash[4-rem];
        }
        else
        count+= hash[0];
        
        hash[rem]++;
    }
    cout << count << endl;
}
}
