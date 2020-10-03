//gfg solution
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int longSubWR(char str[])
{
    int len=strlen(str);
    vector<int>visited(256,-1);
    visited[str[0]]=0;
    
    int cur_len=1,max_len=1,prev_index;
    for(int i=1;i<len;i++)
    {
        prev_index=visited[str[i]];
        if(prev_index==-1||i-cur_len>prev_index)
            cur_len++;
        else
        {
            if(cur_len>max_len)
                max_len=cur_len;
            
            cur_len=i-prev_index;
        }
        visited[str[i]]=i;
    }
    if(cur_len>max_len)
        max_len=cur_len;
        
    return max_len;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        char str[50];
        cin>>str;
        cout<<longSubWR(str)<<endl;
    }
    return 0;
}
