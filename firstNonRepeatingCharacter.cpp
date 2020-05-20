#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int cases;
	cin>>cases;
	while(cases--)
	{
	    int n;
        cin>>n;
	    char str[n];
	    int count[26]={0};
	    cin>>str;
	    queue<char> q; 
	    for(int i=0;i<strlen(str);i++)
	    {
	        q.push(str[i]);
            count[str[i]-'a']++;
            while(!q.empty())
                if(count[q.front()-'a']>1)
                    q.pop();
                else
                    break;
	    }
        if(q.empty())
            cout<<-1<<endl;
        else
            cout<<q.front()<<endl;
	}
	return 0;
}