#include <stdio.h>

int max(int a, int b){  return a>b?a:b;  }

int main() {
    int cases;
	scanf("%d",&cases);
	while(cases--)
	{
	    int m,n;
	    scanf("%d %d",&m,&n);
	    char str1[100],str2[100];
	    scanf("%s %s",str1,str2);
	    int lcsArr[m+1][n+1];
	    for(int i=0;i<m+1;i++)
	    {
	        for(int j=0;j<n+1;j++)
	        {
	            if(i==0||j==0)
	                lcsArr[i][j]=0;
	           else if(str1[i-1]==str2[j-1])
	           {
	               lcsArr[i][j]=1+lcsArr[i-1][j-1];
	           }
	           else
	           {
	                lcsArr[i][j]=max(lcsArr[i-1][j],lcsArr[i][j-1]);
	           }
	        }
	    }
	    printf("%d\n",lcsArr[m][n]);
	}
	return 0;
}