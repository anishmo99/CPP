#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=1;
    queue<int> q;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i%2==0)
                q.push(count++);
            else
                s.push(count++);
        }
        while(!q.empty())
        {
            cout<<q.front()<<" ";
            q.pop();
        }
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}


/*
n = 7
1 
3 2 
4 5 6 
10 9 8 7 
11 12 13 14 15 
21 20 19 18 17 16 
22 23 24 25 26 27 28 
Program ended with exit code: 0
*/

//in python
/*
x=1
for i in range (0,7):
    if(i%2==0):
        l=[]
        for j  in range(0,i+1):
            l.append(x)
            x=x+1
        for k in l:
            print(k,end=" ")
        print("\n")
    else:
        s=[]
        for j in range(0,i+1):
            s.append(x)
            x=x+1
        for f in reversed(s):
            print(f,end=" ")
        print("\n")
*/