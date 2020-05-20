#include <iostream>
#include <list>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        int ln1,ln2,pos;
        cin>>ln1>>ln2>>pos;
        list<int>l1,l2;
        for(int i=0;i<ln1;i++)
        {
            int x;
            cin>>x;
            l1.push_back(x);
        }
        for(int i=0;i<ln2;i++)
        {
            int x;
            cin>>x;
            l2.push_back(x);
        }
        l1.merge(l2);
        int count=0;
        while(count!=pos-1)
        {
            l1.pop_front();
            count++;
        }
        cout<<l1.front()<<endl;
    }
    return 0;
}
