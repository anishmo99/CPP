#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;

int longestDistinct(string s)
{
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        string s;
        cin >> s;
        cout << longestDistinct(s);
    }
    return 0;
}
