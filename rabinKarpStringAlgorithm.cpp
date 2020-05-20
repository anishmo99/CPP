#include <iostream>
#include <cstring>
using namespace std;

void rabinKarp(char pat[],char text[],int q)
{
    int m=strlen(pat);
    int n=strlen(text);
    int i,j;
    int p=0;
    int t=0;
    int h=1;
    int d=256;

    for(i=0;i<m-1;i++)
        h=(h*d)%q;
    
    for(i=0;i<m;i++)
    {
        p=(p*d+pat[i])%q;
        t=(t*d+text[i])%q;
    }

    for(i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(text[i+j]!=pat[j])
                    break;
            }
            if(j==m)
                cout<<"pattern found at index "<<i<<endl;
        }
        
        if(i<n-m)
        {
            t=(d*(t-text[i]*h)+text[i+m])%q;

            if(t<0)
                t+=q;
        }
    }
}

int main()
{
    char text[1000];
    char pat[100];
    cin>>text;
    cin>>pat;
    int q=101;
    rabinKarp(pat,text,q);
    return 0;
}
