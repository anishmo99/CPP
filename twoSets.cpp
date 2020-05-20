//
//  twoSets.cpp
//  C++
//
//  Created by Anish Mookherjee on 28/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//
/*
#include <iostream>
#include <vector>
//kartikeya code
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    ll t=n*(n+1)/2;
    if(t%2!=0)
    {
        cout<<"NO";
    }
    else
    {
        t=t/2;
        ll s=0;
        ll x=n;
        ll e=0;
        vector <int> a;
        while(true)
        {
            a.push_back(x);
            s=s+x;
            --x;
             e=t-s;
            if(e==0)
                break;
            if((s+x)>t)
            {
              s=s+e;
              a.push_back(e);
              break;
            }
            
        }
        cout<<"YES"<<endl;
        cout<<a.size()<<endl;
        for(int i=a.size()-1;i>=0;i--)
            cout<<a[i]<<" ";
        cout<<endl;
        cout<<n-a.size()<<endl;
        for(int i=1;i<=x;i++)
        {
            if(i==e)
                continue;
            else
                cout<<i<<" ";
        }
    }
    
    
    return 0;
}



 //GITHUB CODE
 #include <iostream>
 #include <vector>

 using namespace std;

 typedef long long ll;

 int main() {
   ll n;
   cin >> n;
   ll t = n * (n + 1) / 2;
   if (t % 2) cout << "NO\n";
   else {
     t /= 2;
     vector<int> a;
     ll s = 0;
     ll e = 0;
     ll i = n;
     while (true) {
       a.push_back(i);
       s += i--;
       e = t - s;
       if (!e) break;
       if (e <= i) {
         a.push_back(e);
         break;
       }
     }
     cout << "YES\n" << a.size() << endl;
     for (int j = 0; j < a.size(); j++) {
       cout << a[j];
       if (j < a.size() - 1) cout << " ";
     }
     cout << endl;
     cout << n - a.size() << endl;
     for (ll j = i; j > 0; j--) {
       if (j == e) continue;
       cout << j;
       if ((e != 1 && j > 1) || (e == 1 && j > 2)) cout << " ";
     }
     cout << endl;
   }
 }
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    ll t=n*(n+1)/2;
    if(t/2!=0)
    {
		cout<<"NO"<<endl;
	}
	else
	{
		vector <int> a;
		ll s=0;
		ll x=n;
		ll e=0;
		while(true)
		{
            t=t/2;
            
		}
	}	
}
