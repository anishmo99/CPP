int longprefsuff(string s){
	int j = 0;
	int i = 1;

	vector<int> lps(s.length());
	
	lps[0] = 0;

	while(i < s.length()){
		if(s[i] == s[j]){
			j++;
			lps[i] = j;
			i++;
		}
		else{
			if(j != 0){
				j = lps[j - 1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps.back();
}

int Solution::solve(string A) {
	string rvs = A;
	
	int n = A.length();

	reverse(rvs.begin(), rvs.end());

	A.push_back('$');
	A += rvs;

	return n - longprefsuff(A);
}