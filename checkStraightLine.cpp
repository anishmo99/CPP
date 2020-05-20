class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int X=coordinates[0][0],Y=coordinates[0][1];
        int x_diff=coordinates[1][0]-X,y_diff=coordinates[1][1]-Y;
        for(int i=2;i<coordinates.size();i++)
            if(y_diff*(coordinates[i][0]-X)!=x_diff*(coordinates[i][1]-Y))
               return false;
        return true;
    }
};
