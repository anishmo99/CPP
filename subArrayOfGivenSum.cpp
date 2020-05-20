//
//  subArrayOfGivenSum.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 04/12/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int c,s,flag=0;
        cin>>c>>s;
        int a[c];
        for(int j=0;j<c;j++)
        {
            cin>>a[j];
        }
        int sum=0,k=0;
        for(int j=0;j<c;j++)
        {
            sum+=a[j];
            while(sum>s)
            {
                sum-=a[k++];
            }
            if(sum==s)
            {
                flag=1;
                cout<<k+1<<" "<<j+1<<endl;
                break;
            }
            if (flag==0)
                cout<<-1<<endl;
        }
        }
        
    return 0;
}
