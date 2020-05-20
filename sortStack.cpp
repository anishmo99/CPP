#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void SortedStack :: sort()
{
   vector<int> v;
   int size=s.size();
   for(int i=0;i<size;i++)
   {
       v.push_back(s.top());
       s.pop();
   }
   for(int i=0;i<size;i++)
   {
       s.push(*min_element(v.begin(),v.end()));
       v.erase(min_element(v.begin(),v.end()));
   }
}