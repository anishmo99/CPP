class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int count = 0;
        
        for(int i = 2; i < arr.size(); i++){
            int l = 0;
            int r = i - 1;
            
            while(l < r){
                if(arr[l] + arr[r] > arr[i]){
                    count += r - l;
                    r--;
                }
                else
                    l++;
            }
        }
        
        return count;
    }
};