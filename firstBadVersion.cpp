#include <iostream>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1,high=n;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(isBadVersion(mid))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};

// or

class Solution {
public:
    int firstBadVersion(int n) {
        while(n >= 1){
            if(!isBadVersion(n))
                return ++n;
            n--;
        }
        return 1;
    }
};
