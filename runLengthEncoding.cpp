#include <iostream>
#include <cstring>

using namespace std;

char *encode(char *src)
{
    string str(src);
    char *res=(char*)malloc(1000);
    int j=0;
    for(int i=0;i<str.length();i++)
    {
        res[j++]=str[i];
        int count=1;
        i++;
        while(i<str.length()&&str[i]==str[i-1])
        {
            i++;
            count++;
        }
        res[j++]='0'+count;
    }
    return res;
}