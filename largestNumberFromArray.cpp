#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool checkComp(string s1,string s2)
{
    string s1s2=s1.append(s2);
    string s2s1=s2.append(s1);

    return s1s2.compare(s2s1)>0?1:0;
}

int main() {
	int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        vector<string> str;
        string input;
        for(int i=0;i<n;i++)
        {
            cin>>input;
            str.push_back(input);
        }
        sort(str.begin(),str.end(),checkComp);
        for(int i=0;i<n;i++)
        {
            cout<<str[i];
        }
        cout<<endl;
    }
	return 0;
}