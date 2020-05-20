class Solution {
public:
    bool isPerfectSquare(int num) {
        int n=1;
        while(true)
        {
            if(n*n==num)
                return true;
            else if(n*n>num)
                return false;
            n++;
        }
    }
};
