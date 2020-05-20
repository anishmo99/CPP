#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		long long x,y,l,r;
		cin>>x>>y>>l>>r;
		if(l<0)	l=0;
		long long max=-1,func,index;
        while(r-l)
        {
			func=(x&l)|(y&l);
            if(max<func)
            {
                max=func;
                index=l;
            }
            l++;
        }
        cout<<index<<endl;
	}
	return 0;
}
