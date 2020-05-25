#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

bool isPangram(string s)
{
	int hash[26]={0};
	transform(s.begin(),s.end(),s.begin(),::tolower);
	for(char& c:s)
		hash[c-'a']++;
	for(int& i:hash)
		if(i>=1)
			continue;
		else return false;

	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	string s;
	getline(cin,s);
	if(isPangram(s))
		cout<<"pangram\n";
	else
		cout<<"not pangram\n";
}