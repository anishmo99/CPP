#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int cases;
	cin>>cases;
	while(cases--)
	{
	    int i;
	    string str;
	    cin>>str;
	    int n=str.length();
	    for(i=0;i<n;)
	    {
           if(i+2<n && str[i]=='R' && str[i+1]=='Y' && str[i+2]=='Y')
            {
                i+=3;
            }
            else if(i+1<n && str[i]=='R' && str[i+1]=='Y')
            {
                i+=2;
            }
            else if(i<n && str[i]=='R')
            {
                i+=1;
            }
        else 
            break;
	    }
	    if(i>=n)
	        cout<<"YES";
	    else 
	        cout<<"NO";
	    cout<<endl;
    }
	return 0;
}