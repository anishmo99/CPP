class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> v(arr.size());
        
        int i = 0, j = 1;
        
        int m1axc = arr[0];
        while(j <= k){
            maxc = max(maxc, arr[j++]);
        }
        
        for(int i = 0; j < arr.size(); i++){
            arr[i] = maxc;
            maxc = max(maxc, arr[j]);
            j++;
        }
        
        while(i < arr.size()){
            arr[i++] = maxc;
        }
        
        for(int i : arr){
            cout << i << " ";
        }
        
        return accumulate(arr.begin(), arr.end(), 0);
    }
};