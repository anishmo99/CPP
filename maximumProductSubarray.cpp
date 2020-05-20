class Solution {
public:
    int maxProduct(vector<int>& nums) {
    if(nums.size()==0)    return -1;
    int cur_max,cur_min,final_max;
    cur_max=cur_min=final_max=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<0)
            swap(cur_max,cur_min);

        cur_max=max(nums[i],cur_max*nums[i]);
        cur_min=min(nums[i],cur_min*nums[i]);

        final_max=max(cur_max,final_max);
    }
    return final_max;
    }
};

/*
 //geeksforgeeks wrong test case for n -> 9185
 #include <iostream>
 #include <utility>

 using namespace std;

 long long int maxProdSubArray(long long int arr[],int n)
 {
     if(n==0)    return -1;
     long long int cur_max,cur_min,final_max;
     cur_max=cur_min=final_max=arr[0];
     for(int i=1;i<n;i++)
     {
         if(arr[i]<0)
             swap(cur_max,cur_min);

         cur_max=max(arr[i],cur_max*arr[i]);
         cur_min=min(arr[i],cur_min*arr[i]);

         final_max=max(cur_max,final_max);
     }
     return final_max;
 }

 int main()
 {
     int cases;
     cin>>cases;
     while(cases--)
     {
         int n;
         cin>>n;
         long long int arr[n];
         for(int i=0;i<n;i++)
             cin>>arr[i];
         cout<<maxProdSubArray(arr,n)<<endl;
     }
 }
*/
