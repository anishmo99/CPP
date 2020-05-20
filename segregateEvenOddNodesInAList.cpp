#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        list <int> l;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            l.push_back(x);
        }
        vector<int>even,odd;
        for(auto i:l)
        {
            if(i%2==0)
                even.push_back(i);
            else
                odd.push_back(i);
        }
        l.clear();
        for(auto i:even)
            l.push_back(i);
        for(auto i:odd)
            l.push_back(i);
        for(auto i : l)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
