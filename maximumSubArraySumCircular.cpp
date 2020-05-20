class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total=0;
        int minSum=numeric_limits<int>::max(),cur_min=0;
        int maxSum=numeric_limits<int>::min(),cur_max=0;
        for(auto& a:A)
        {
            cur_max=max(cur_max+a,a);
            maxSum=max(cur_max,maxSum);
            cur_min=min(cur_min+a,a);
            minSum=min(cur_min,minSum);
            total+=a;
        }
        return maxSum>0?max(maxSum,total-minSum):maxSum;
    }
};
/*
 //geeksforgeeks
 #include <iostream>
 using namespace std;

 int maxSubArrSumCircular(int arr[],int n)
 {
     if(n==0)    return 0;
     int total=arr[0];
     int minSum=arr[0],cur_min=arr[0],maxSum=arr[0],cur_max=arr[0];
     for(int i=1;i<n;i++)
     {
         cur_max=max(cur_max+arr[i],arr[i]);
         maxSum=max(maxSum,cur_max);
         cur_min=min(cur_min+arr[i],arr[i]);
         minSum=min(minSum,cur_min);
         total+=arr[i];
     }
     if(total==minSum)   return maxSum;
     return max(maxSum,total-minSum);
 }

 int main() {
     int cases;
     cin>>cases;
     while(cases--)
     {
         int n;
         cin>>n;
         int arr[n];
         for(int i=0;i<n;i++)
             cin>>arr[i];
         cout<<maxSubArrSumCircular(arr,n)<<endl;
     }
     return 0;
 }
 */
