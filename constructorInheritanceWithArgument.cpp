#include<iostream>
using namespace std;

class Base
{
    int i;
public:
    Base(int x){cout<<"Base constructor"<<endl;
        i=x;
    }
    ~Base(){cout<<"Base destructor"<<endl;}
    void show_Base(){cout<<"Base - i : "<<i<<endl;}
};
class Derived : public Base
{
    int j;
public:
    Derived(int x,int y):Base(y){cout<<"Derived constructor"<<endl;
        j=x;
    }
    ~Derived(){cout<<"Derived destructor"<<endl;}
    void show_Derived(){cout<<"Derived - j : "<<j<<endl;}
};
int main()
{
    Derived x(8,3);
    x.show_Base();
    x.show_Derived();
}
