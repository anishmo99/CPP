#include <iostream>
#include <cstring>

using namespace std;

bool isRotation(char str1[],char str2[])
{
    if(strlen(str1)!=strlen(str2))
        return false;
    strcat(str1,str1);
    if(strstr(str1,str2)!=NULL)
        return true;
    else
        return false;

}

int main()
{
    char str1[100],str2[100];
    cin>>str1>>str2;
    cout<<isRotation(str1,str2)<<endl;
}
