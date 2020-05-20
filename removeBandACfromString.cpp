#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void remBandAC(char *str)
{
    char str1[200]={' '};
    int j=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='b')
            continue;
        else if(str[i]=='a'&&str[i+1]=='c')
            i+=1;
        else
            str1[j++]=str[i];
    }
    printf("%s",str1);
}

int main() {
	int cases;
	scanf("%d",&cases);
    while(cases--)
    {
        char *str;
        scanf("%s",str);
        remBandAC(str);
        printf("\n");
    }
	return 0;
}

/*

accepted code : 

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void remBandAC(string str)
{
    string str1="";
    int j=0;
    for(int i=0;i<str.length();)
    {
        if(str[i]=='b')
            i++;
        else if(str[i]=='a'&&str[i+1]=='c')
            i+=2;
        else
            str1+=str[i++];
    }
    cout<<str1;
}

int main() {
	int cases;
	scanf("%d",&cases);
    while(cases--)
    {
        string str;
        cin>>str;
        remBandAC(str);
        printf("\n");
    }
	return 0;
}
*/

/*

using char array

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void remBandAC(char *str)
{
    char str1[200]={' '};
    int j=-1;
    for(int i=0;i<strlen(str);)
    {
        if(str[i]=='b')
            i++;
        else if(str[i]=='a'&&str[i+1]=='c')
            i+=2;
        else
            str1[++j]=str[i++];
    }
    cout<<str1;
}

int main() {
	int cases;
	scanf("%d",&cases);
    while(cases--)
    {
        char *str;
        cin>>str;
        remBandAC(str);
        printf("\n");
    }
	return 0;
}
*/