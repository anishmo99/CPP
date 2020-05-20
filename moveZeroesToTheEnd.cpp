#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
        int numsCount=nums.size(),count=0;
        for(auto i=nums.begin();i!=nums.end();i++){
            if(count>numsCount)
                break;
            if(*i==0){
                nums.erase(i);
                nums.push_back(0);
                i--;
            }
            count++;
    }
}
