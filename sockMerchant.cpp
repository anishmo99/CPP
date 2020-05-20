#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sockMerchant(int n, vector<int> ar) {
    int pairCount=0,eachCount=0;
    sort(ar.begin(),ar.end());
    int size=0;
    while(size<ar.size())
    {
        if(ar[size]==ar[size+1])
            eachCount++;
        else
        {
            pairCount+=(int)(eachCount+1)/2;
            eachCount=0;
        }
        size++;
    }
    return pairCount;
}
