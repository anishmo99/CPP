#include<iostream>
using namespace std;
class arr
{
    int a[10];
    public:
    void set_data(int x,int i)
    {
        a[i]=x;
    }
   void max_value(int n)
   {
       int m;
       m=a[0];
       for(int i=0;i<n;i++)
       {
           if(m<a[i])
            m=a[i];
       }
       cout<<"Maximum value is : "<<m;
   }
    void min_value(int n)
   {
       int m;
       m=a[0];
       for(int i=0;i<n;i++)
       {
           if(m>a[i])
            m=a[i];
       }
       cout<<"\nMinimum value in array is : "<<m;
   }
   void sort_value(int n)
   {
       for(int i=0;i<n-1;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               if(a[i]<a[j])
               {
                   int temp;
                   temp=a[i];
                   a[i]=a[j];
                   a[j]=temp;
               }
           }
       }
       cout<<endl<<"The descending order is : ";
       for(int i=0;i<n;i++)
       {
           cout<<a[i]<<" ";
       }
   }

};
int main()
{
    void set_data(int);
    void max_value(int);
    void min_value(int);
    void sort_value(int);
    arr a1;
    int n,t;
    cout<<"How many value do you want to enter? :: ";
    cin>>n;
    cout<<"Enter element : ";
    for(int i=0;i<n;i++)
    {
        cin>>t;
        a1.set_data(t,i);
    }
    a1.max_value(n);
    a1.min_value(n);
    a1.sort_value(n);

}
