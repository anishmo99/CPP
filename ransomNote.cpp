#include <iostream>
#include <cstring>
using namespace std;

bool canConstruct(string s2, string s1) {
    int count[26]={0};
    for(int i=0;i<s1.length();i++)
    {
        count[s1[i]-'a']++;
    }
    for(int i=0;i<s2.length();i++)
    {
        if(count[s2[i]-'a']==0)
            return false;
        count[s2[i]-'a']--;
    }
    return true;
}

int main()
{
    string s1,s2;
    //can s2 be constructed from s1;
    cin>>s1>>s2;
    if(canConstruct(s2,s1))
        cout<<"true"<<endl;
    else    cout<<"false"<<endl;
    return 0;
}
