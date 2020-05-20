 #include <iostream>
 using namespace std;

 int numSquareSum(int n)
    {
        int sum=0;
        while(n)
        {
            int r=n%10;
            sum+=r*r;
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow=n,fast=n;
        do
        {
            slow=numSquareSum(slow);    
            fast=numSquareSum(numSquareSum(fast));
        }while(slow!=fast);
        return (slow==1);
    }

int main()
{
    int num;
    cin>>num;
    if(isHappy(num))    cout<<"true";
    else    cout<<"false";
    return 0;
}