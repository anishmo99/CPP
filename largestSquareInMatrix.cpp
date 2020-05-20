#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int r,c;
        int max=0;
        scanf("%d %d",&r,&c);
        vector<vector<int> >mat(r,vector<int> (c,0));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                scanf("%d",&mat[i][j]);
        vector<vector<int> >auxMat(r,vector<int> (c,0));
        for(int i=0;i<r;i++)
            auxMat[i][0]=mat[i][0];
        for(int j=0;j<c;j++)
            auxMat[0][j]=mat[0][j];

        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(mat[i][j]==1)
                {
                    auxMat[i][j]=min(auxMat[i][j-1],min(auxMat[i-1][j],auxMat[i-1][j-1]))+1;
                }
                else
                    auxMat[i][j]=0;
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(max<auxMat[i][j])
                    max=auxMat[i][j];
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
