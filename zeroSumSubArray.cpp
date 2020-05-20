#include <iostream>
#include <unordered_map>

using namespace std;

int countSubArray(int arr[],int n)
{
    unordered_map<int,int>map;
    int sum=0,int count=0;
    map[0]++;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(map.find(sum)!=map.end())
            count+=map[sum];
        map[sum]++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        cout<<countSubArray(arr,n)<<endl;
    }
    return 0;
}

/*
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7
Output:
6
4
*/
