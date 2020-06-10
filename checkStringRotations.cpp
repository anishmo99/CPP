// CPP approach
#include <iostream>
using namespace std;

bool isRotation(string s1,string s2)
{
    if(s1.length()!=s2.length())
        return false;
    string temp=s1+s1;
    return temp.find(s2)!=string::npos;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        string s1,s2;
        cin>>s1>>s2;
        cout<<isRotation(s1,s2)<<endl;
    }
    return 0;
}

// C approach
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
