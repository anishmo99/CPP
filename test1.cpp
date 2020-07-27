#include <iostream>
#include <cstring>

using namespace std;

int strStr(string haystack, string needle) {
    int i = 0,j = 0;
    bool flag = false;
    int pos = 0;
    if(haystack.length() == 0 and needle.length() == 0)
        return 0;
    if(haystack.length() == 0 and needle.length() > 0)
        return -1;
    if(haystack.length() > 0 and needle.length() == 0)
        return 0;
    if(haystack == needle)
        return 0;
    
    while(j < haystack.length())
    {
        if(i == needle.length())
            return pos;
        if(haystack.at(j) == needle.at(i))
        {
            if(!flag)
            {
                flag = true;
                pos = j;
            }
            i++;
            // cout << haystack.at(j);
        }
        else
        {
            i = 0;
        }
        j++;
    }
    return pos ? pos : -1;
}


int main(){
    string haystack, needle;
    cin >> haystack >> needle;
    cout << strStr(haystack, needle);
}