#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int index=0;
        char str1[100];
        char str2[100];
        int len1=sizeof(str1)/sizeof(str1[0]);
        cin>>str1>>str2;
        for(int i=0;i<len1;i++)
        {
            int flag=0;
            for(int j=0;j<strlen(str2);j++)
            {
                if(str1[i]==str2[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                str1[index++]=str1[i];
        }
        cout<<str1<<endl;
    }
    return 0;
}