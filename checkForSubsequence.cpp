#include <iostream>
using namespace std;


bool isSubsequence(string s, string t) {
    int i=0;
    int j=0;
    while(j<t.length()){
        if(s[i]==t[j])
            i++;
        j++;
    }
    return i==s.length();
}

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        string s,t;
        cin>>s>>t;
        cout<<isSubsequence(s,t)<<endl;
    }
    return 0;
}
