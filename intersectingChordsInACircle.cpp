int Solution::chordCnt(int A) {
    if(A == 0 or A == 1)
        return 1;

    vector<long long int> cat(A + 1, 0);

    cat[0] = cat[1] = 1;

    for(int i = 2; i <= A; i++){
        for(int j = 0; j < i; j++){
            cat[i] = (cat[i] + cat[j] * cat[i - j - 1]) % 1000000007;
        }
    }

    return cat[A] % 1000000007;
}
