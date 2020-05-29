//leetcode solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>hash_set;
        int i=0,j=0;
        int count=0;
        while(j<s.length())
        {
            if(hash_set.find(s.at(j))==hash_set.end())
            {
                hash_set.insert(s.at(j));
                j++;
                count=max(count,j-i);
            }
            else
            {
                hash_set.erase(s.at(i));
                i++;
            }
        }
        return count;
    }
};


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
