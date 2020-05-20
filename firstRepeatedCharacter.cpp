#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        string str;
        cin>>str;
        int flag=0;
        unordered_map<char,int>map;
        for(int i=0;i<str.length();i++)
        {
            map[str[i]]++;
            if(map[str[i]]>1)
            {
                cout<<str[i]<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<-1<<endl;
    }
    return 0;
}
