//
// Created by Anish Mookherjee on 30/05/20.
//

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

#define EB emplace_back
#define PB push_back
#define F first
#define S second


void overlappingIntervals(vector<pair<int,int>> intervals)
{
    vector<pair<int,int>> result;
    sort(intervals.begin(),intervals.end(),[](pair<int,int> p1,pair<int,int> p2){return p1.F<p2.F;});
    result.PB(intervals.front());
    for(int i=1;i<intervals.size();i++)
    {
        if(result.back().S<intervals[i].F)
            result.PB(intervals[i]);
        else
            result.back().S=max(result.back().S,intervals[i].S);
    }
    for(auto x:result)
        cout<<x.F<<" "<<x.S<<" ";
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin>>n;
        vector<pair<int,int>> intervals;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            intervals.EB(a,b);
        }
        overlappingIntervals(intervals);
        cout<<endl;
    }
    return 0;
}
