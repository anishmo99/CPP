int minDist(int a[], int n, int x, int y) {
    int pos_x = -1, pos_y = -1;
    int min_dis = INT_MAX, cur_dis = -1;
    int i = 0;
    while(i < n){
        if(a[i] == x)
            pos_x = i;
            
        if(a[i] == y)
            pos_y = i;
            
        if(pos_x != -1 and pos_y != -1){
            cur_dis = abs(pos_x - pos_y);
            
            if(min_dis > cur_dis)
            min_dis = cur_dis;
        }
        i++;
    }
    if(pos_x == -1 or pos_y == -1)
        return -1;
    return min_dis;
}