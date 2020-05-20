#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char s[n][100];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(s[i],s[j])>0)
			{
				char temp[100];
				strcpy(temp,s[i]);
				strcpy(s[i],s[j]);
				strcpy(s[j],temp);
			}	
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}
