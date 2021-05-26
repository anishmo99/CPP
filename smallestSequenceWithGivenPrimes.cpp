vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> v(D, 0);
    
    int ia = 0, ib = 0, ic = 0;
    int na = A, nb = B, nc = C;
    
    for(int i = 0; i < D; i++){
        int next = min(na, min(nb, nc));
        
        v[i] = next;
        
        if(next == na){
            na = A * v[ia++];
        }
        
        if(next == nb){
            nb = B * v[ib++];
        }
        
        if(next == nc){
            nc = C * v[ic++];
        }
    }
    
    return v;
}