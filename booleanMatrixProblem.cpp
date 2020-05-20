#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        int r,c,i,j;
        cin>>r>>c;
        int mat[r][c];
        vector<int>rowFlag(r,0);
        vector<int>colFlag(c,0);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                cin>>mat[i][j];
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(mat[i][j]==1)
                {
                    rowFlag[i]=1;
                    colFlag[j]=1;
                }
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(rowFlag[i]==1||colFlag[j]==1)
                    mat[i][j]=1;
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
	return 0;
}