//leetcode solution
class Solution {
public:
    bool isSubsequence(string word,string s)
    {
        int m=word.length(),n=s.length();
        int i,j;
        for(i=0,j=0;i<m&&j<n;j++)
            if(word.at(i)==s.at(j))
                i++;
        return i==m;
    }
    string findLongestWord(string s, vector<string>& d) 
    {
        string result="";
        for(string word:d)
        {
            if(result.length()<=word.length()&&isSubsequence(word,s)&&(result>word||result.length()<word.length()))
            {
                result=word;
            }
        }
        return result;
    }
};

//geeksforgeeks solution
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSubsequence(string word,string s)
{
    int m=word.length(),n=s.length();
    int i,j;
    for(i=0,j=0;i<m&&j<n;j++)
        if(word.at(i)==s.at(j))
            i++;
    return i==m;
}

string findLongestWord(string s, vector<string>& d) 
{
    string result;
    int length=0;
    for(string word:d)
    {
        if(length<word.length()&&isSubsequence(word,s))
        {
            result=word;
            length=word.length();
        }
    }
    return result;
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        vector<string> dict;
        while(n--)
        {
            string x;
            cin>>x;
            dict.push_back(x);
        }
        string s;
        cin>>s;
        cout<<findLongestWord(s,dict)<<endl;
    }
}