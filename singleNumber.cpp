#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int first=0,second=1;second<nums.size();first++,second++){
            if(nums[first]==nums[second]){
                first++;
                second++;
                }
            else return nums[first];
            }
        return nums.back();
    }

//TLE

/*int singleNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(count(nums.begin(),nums.end(),nums[i])==1){
                return nums[i];
            }
        }
        return 0;
    }*/