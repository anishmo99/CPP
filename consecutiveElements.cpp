#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        string s;
        cin>>s;
        vector<char>vec;
        vec.push_back(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
            continue;
            vec.push_back(s[i]);
        }
        for(auto& i:vec)
            cout<<i;
           cout<<endl;
    }
    return 0;
}
