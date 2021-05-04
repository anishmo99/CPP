int Solution::longestSubsequenceLength(const vector<int> &A) {
    if(A.size() <= 1)
        return A.size();
    
    vector<int> forw(A.size(), 1);
    vector<int> backw(A.size(), 1);
    vector<int> ans(A.size(), 0);

    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < i; j++){
            if(A[i] > A[j] and forw[i] < forw[j] + 1){
                forw[i] = forw[j] + 1;
            }
        }
    }

    for(int i = A.size() - 2; i >= 0; i--){
        for(int j = A.size() - 1; j > i; j--){
            if(A[i] > A[j] and backw[i] < backw[j] + 1){
                backw[i] = backw[j] + 1;
            }
        }
    }

    for(int i = 0; i < A.size(); i++){
        ans[i] = forw[i] + backw[i] - 1;
    }

    return *max_element(ans.begin(), ans.end());
}
