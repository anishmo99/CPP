#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int wordRank(string s){

    int rank = 1;
    int n = s.size();

    map<char, int> freq;
    for(auto x: s)
    {
        freq[x]++;
    }
    for(auto x: freq)
    {
        if(x.second > 1)
            return 0;
    }

    auto smaller = [&](string str){
        int count = 0;
        char c = str[0];
        for(int i=1; i<str.size(); i++)
        {
            if(str[i]<c)
            {
                count++;
            }
        }
        return count;
    };

    auto fac = [ & ] ( int n ) {
        int temp = 1;
        for ( int i = 1 ; i <= n ; i ++ ) {
            temp = temp * i;
        }
        return temp;
    };

    int fact = fac(n);

    for(int i=0; i<n; i++){
        fact = fact / (n - i);

        rank+=smaller(s.substr(i, n-i))*fact;
    }
    return rank % 1000003;

}

int main()
{

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        cout << wordRank(s) << endl;
    }

    return 0;
}