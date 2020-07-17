#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];
        int first=-999;
        int second=-999;
        for(int i=0;i<n;i++)
        {
            if(vec[i]>first)
            {
                second=first;
                first=vec[i];
            }
            else if(vec[i]>second && vec[i]!=first) 
                second = vec[i];
        }
    
        cout<<(second==-999?-1:second)<<endl;
    }
	return 0;
}