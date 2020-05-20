#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
 using namespace std;

 void findPairs(int a1[],int a2[],int n1,int n2,int x)
 {
    unordered_map<int,int>m;
    for(int i=0;i<n2;i++)
    {
        m[a2[i]]++;
    }
    vector<int>v;
    for(int i=0;i<n1;i++)
    {
        if(m[x-a1[i]])
               v.push_back(a1[i]);
    }
    sort(v.begin(),v.end());
    bool flag=0,start=0;
    for(int i:v)
    {
        if(start)
            printf(", %d %d",i,x-i);
        else
        {
            start=1;
            printf("%d %d",i,x-i);
            flag=1;
        }
    }
    if(!flag)
        printf("-1");
    printf("\n");
}

 int main(int argc, char const *argv[])
 {
     int cases;
     scanf("%d",&cases);
     while(cases--)
     {
        int n1,n2,x;
        scanf("%d %d %d",&n1,&n2,&x);
        int a1[n1];
        int a2[n2];
        for(int i=0;i<n1;i++)
            scanf("%d",&a1[i]);
        for(int i=0;i<n2;i++)
            scanf("%d",&a2[i]);
        findPairs(a1,a2,n1,n2,x);
     }
     return 0;
 }
