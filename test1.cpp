int NewNumber{int n}{
    int res;
    int k = 0;
    while(n!=0){
        int r = n%10;
        res = (9-r)*pow(10,k++)+res;
        n /= 10;
    }
    return res;
}