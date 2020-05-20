#include <iostream>
#include <vector>
using namespace std;

int first(vector<int> arr,int low,int high)
{
	if(high>=low)
	{
		int mid=low+(high-low)/2;
		if((mid==0||arr[mid-1]==0) && arr[mid]==1)
			return mid;
		else if(arr[mid]==0)
			return first(arr,mid+1,high);
		else
			return first(arr,0,mid-1);	
	}
	return -1;
}

/*

// time complexity O(mlogn)

int rowMax(vector<vector<int> > mat,int r,int c)
{
	int max_row_index=0,max=-1,index;
	for(int i=0;i<r;i++)
	{
		index=first(mat[i],0,c-1);
		if(index!=-1&&c-index>max)
		{
			max=c-index;
			max_row_index=i;
		}
	}
	return max_row_index;
}
*/

//efficient soluntion O(m+n) in worst case

int rowMax1(vector<vector<int> > mat,int r,int c)
{
	int max_row_index=0,index;
	int j=first(mat[0],0,c-1);
	if(j==-1)	j=c-1;
	for(int i=1;i<r;i++)
	{
		while(j>=0&&mat[i][j]==1)
		{
			j--;
			max_row_index=i;
		}
	}
	return max_row_index;
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
		cout<<rowMax1(mat,r,c)<<endl;
	}

}