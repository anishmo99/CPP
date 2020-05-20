#include <iostream>
#include <vector>
using namespace std;

void floodFillUtil(vector<vector<int>>& screen,int x,int y,int prevC,int newC)
{
    if(x<0||y<0||x>=screen.size()||y>=screen[0].size())
        return;
    if(screen[x][y]!=prevC)
        return;
    if(screen[x][y]==newC)
        return;
        
    screen[x][y]=newC;
    
    floodFillUtil(screen,x+1,y,prevC,newC);
    floodFillUtil(screen,x-1,y,prevC,newC);
    floodFillUtil(screen,x,y+1,prevC,newC);
    floodFillUtil(screen,x,y-1,prevC,newC);
}
void floodFill(vector<vector<int>>& screen,int x,int y,int newC)
{
    int prevC=screen[x][y];
    floodFillUtil(screen,x,y,prevC,newC);
    for(int i=0;i<screen.size();i++)
    {
        for(int j=0;j<screen[0].size();j++)
        {
            cout<<screen[i][j]<<" ";
        }
    }
}

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > screen(r,vector<int> (c,0));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>screen[i][j];
        int x,y,color;
        cin>>x>>y>>color;
        floodFill(screen,x,y,color);
        cout<<endl;
    }
    return 0;
}
/*
class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int color,int paint)
    {
        if(i<0 || j<0)
            return;
        if(i>=image.size() || j>=image[0].size())
            return;
        if(image[i][j]!=color)
        {
            return;
        }
        image[i][j]=paint;
        dfs(image,i+1,j,color,paint);
        dfs(image,i-1,j,color,paint);
        dfs(image,i,j+1,color,paint);
        dfs(image,i,j-1,color,paint);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size() && image[sr][sc]!=newColor)
        {
            dfs(image,sr,sc,image[sr][sc],newColor);
        }
        return image;
    }
};
*/
