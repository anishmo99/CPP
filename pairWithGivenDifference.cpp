int Solution::solve(vector<int> &A, int B) {
	map<int, int> mp;
	
	for(int i = 0; i < A.size(); i++){
	    if(mp[A[i]])
	        return true;
	    mp[A[i] - B]++;
	    mp[A[i] + B]++;
	}
	return false;
}

// or

int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int i = 0,j = 1;
	while(i < A.size() && j < A.size())
	{
	    if(A[j] - A[i] == B && i != j )
	    { 
	        return 1;
	    }
	    else
	    if(A[j] - A[i] < B)
	    	j++;
	    else
	    	i++;
	}
	return 0;
}