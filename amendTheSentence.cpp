#include <iostream>
#include <cstring>
using namespace std;

void amendSentence(char *str)
{
	for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            str[i]=str[i]+32;
            if(i!=0)
				cout<<" ";
        	cout<<str[i];
		}
		else	cout<<str[i];
    }
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
	   char *str;
       cin>>str;
       amendSentence(str);
       cout<<endl;
	}
	return 0;
}