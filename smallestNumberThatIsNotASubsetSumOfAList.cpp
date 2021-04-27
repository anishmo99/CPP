class Solution{   
public:
    long long findSmallest(long long arr[], int n) {
        long long int ans = 0;
        
        for(int i = 0; i < n; i++){
            
            if(ans + 1 < arr[i])
                break;
            
            ans += arr[i];
        }
        
        return ans + 1;
    }
};