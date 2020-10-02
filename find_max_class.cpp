#include<iostream>
using namespace std;

class Max
{
    private:
    int a[50];
    int number;
    int max;
    public:
    void set_value();
    void find_max();
    void display_max();
};

void Max :: set_value()
{
    cout<<"How many number do you want to enter? :: ";
    cin>>number;
    cout<<"Enter "<<number<<" value : ";
    for(int i=0; i<number; i++)
        cin>>a[i];
}

void Max :: find_max()
{
    max = a[0];
    for(int i=0; i<number; i++)
        if(a[i]>max)
            max = a[i];
}

void Max :: display_max()
{
    cout<<"Maximum value is : "<<max;
}

int main()
{
    void set_value();
    void find_max();
    void display_max();
    Max m1;
    m1.set_value();
    m1.find_max();
    m1.display_max();
    return 0;
}