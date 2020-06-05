#include <iostream>
#include <string>
#include <map>

using namespace std;

bool hasPalindromePermutation(const string& str)
{
    // check if any permutation of the input is a palindrome
    map<char,int>m;
    for(auto ch:str)
        m[ch]++;
    
    string org;
    for(auto x:m)
    {
        if(x.second%2!=0&&org!="")
            return false;
        else if(x.second%2!=0)
            org=" ";
    }
    
    return true;
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        string str;
        cin>>str;
        if(hasPalindromePermutation(str))
            cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;
    }
}
