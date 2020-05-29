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

    auto fac = [&] ( int n ) {
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

/*
 * //simpler code without lambda
 * #include <iostream>
#include <map>
#include <algorithm>

using namespace  std;

inline int fact(int n){
    return n<=1?1:n*fact(n-1);
}

inline int smaller(string str){
    int count=0;
    char c=str[0];
    for(int i=1;i<str.length();i++)
        if(str[i]<c)
            count++;
    return count;
}

int wordRank(string s){
    int len=s.length();
    map<char,int>m;

    for(char c:s)
        m[c]++;

    for(auto x:m)
        if(x.second>1)
            return 0;

    int factorial=fact(len);

    int rank=1;

    for(int i=0;i<len;i++){
        factorial/=len-i;

        rank+=smaller(s.substr(i,n-i))*factorial;
    }

    return rank%1000003;
}

int main(){
    int cases;
    cin>>cases;
    while(cases--){
        string s;
        cin>>s;
        cout<<wordRank(s)<<endl;
    }
}
 */