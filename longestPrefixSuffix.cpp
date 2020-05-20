#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int cases;
	cin>>cases;
	while(cases--)
	{
	    char pat[100000];
	    cin>>pat;
	    int m=strlen(pat);
	    int len=0,i=1;
	    vector<int> lcs(m);
	    while(i<m)
	    {
	        if(pat[len]==pat[i])
	        {
	            len++;
	            lcs[i]=len;
	            i++;
	        }
	        else if(len!=0)
	        {
	            len=lcs[len-1];
	        }
	        else
	        {
	            lcs[i]=0;
	            i++;
	        }
	    }
	    cout<<lcs[i-1]<<endl;
	}
	return 0;
}