#include <iostream>
#include <cstring>
using namespace std;

int countOccurencesAnagrams(string s,string p)
{
    int answer=0;
    if(s.length()==0||p.length()>s.length())    return 0;
    
    int hash[26]={0};
    for(char& i:p)
        hash[i-'a']++;
        
    int left=0,right=0,count=p.length();
    
    while(right<s.length())
    {
        if(hash[s[right++]-'a']-->=1)
            count--;
        if(count==0)
            answer++;
        if(right-left==p.length()&&hash[s[left++]-'a']++>=0)
            count++;
    }
    return answer;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        string s,p;
        cin>>s>>p;
        cout<<countOccurencesAnagrams(s,p)<<endl;
    }
    return 0;
}
