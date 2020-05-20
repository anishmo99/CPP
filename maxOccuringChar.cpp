#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        int keep[26]={0},max=0;
        char result=' ';
        char str1[100];
        cin>>str1;
        for(int i=0;i<strlen(str1);i++)
        {
            keep[str1[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(max<keep[i])
            {
                max=keep[i];
                result=(char)(i+'a');
            }
        }
        cout<<result<<endl;
    }
    return 0;
} 
