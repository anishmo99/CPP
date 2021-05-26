class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        
        while(K--){
            int mini = INT_MAX;
            
            int index = 0;
            for(int i = 0; i < A.size(); i++){
                if(mini > A[i]){
                    index = i;
                    mini = A[i];
                }
            }
            
            A[index] = -A[index];
            
        }
        
        
        return accumulate(A.begin(), A.end(), 0);
    }
};