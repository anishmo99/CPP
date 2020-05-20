#include <iostream>
#include <vector>
using namespace std;

int first(vector<int> arr,int low,int high)
{
    if(high>=low)
    {
        int mid=low+(high+low)/2;
        if((mid==0||arr[mid-1]==0)&&arr[mid]==1)
            return mid;
        else if(arr[mid]==0)
            return first(arr,mid+1,high);
        else
            return first(arr,0,mid-1);
    }
    return -1;
}

int rowMin(vector<vector<int> > mat,int r,int c)
{
    int min_row_index=0;
    int j=first(mat[0],0,c-1);
    for(int i=1;i<r;i++)
    {
        while(j!=-1&&j<c&&mat[i][j]==0)
        {
            j++;
            min_row_index=i;
        }
    }
    if(j==-1)   return -1;
    return min_row_index;
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > mat(r,vector<int> (c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>mat[i][j];
            }
        }
        cout<<rowMin(mat,r,c)<<endl;
    }
}