#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        vector<int>even,odd;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x%2==0)
                even.push_back(x);
            else
                odd.push_back(x);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        for(int i=0;i<even.size();i++)
        {
            cout<<even[i]<<" ";
        }
        for(int i=0;i<odd.size();i++)
        {
            cout<<odd[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}