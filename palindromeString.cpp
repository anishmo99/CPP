#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
    int n;
    cin>>n;
	string str1;
    cin>>str1;
    int len=str1.length();
    string reverse="";
    for(int i=0;i<len;i++)
    {
        reverse=str1[i]+reverse;
    }
    if(reverse==str1)
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;    
	}
	return 0;
}