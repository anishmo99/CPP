/*
print the elements of an array in the decreasing frequency,
if 2 numbers have same frequency then print the one which came first. 
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cstdio>

using namespace std;

unordered_map<int,int> m2; //stores index of the respective elements in the array

bool sortByVal( pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second==p2.second)
        return m2[p1.first]<m2[p2.first];
    return p1.second>p2.second;
}

void sortEleByFreq(int arr[],int n)
{
    unordered_map<int,int> m; //stores the number of same elements present
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
        if(m2[arr[i]]==0)
            m2[arr[i]]=i+1;
    }
    copy(m.begin(),m.end(),back_inserter(v));
    sort(v.begin(),v.end(),sortByVal);
	for (int i = 0; i < v.size(); i++)  
        for (int j = 0; j < v[i].second; j++)  
            printf("%d ",v[i].first);
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
		int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        sortEleByFreq(arr,n);
		printf("\n");
    }
    return 0;
}

