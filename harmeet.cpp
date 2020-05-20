#include <iostream>
using namespace std;
class base{
public:
    virtual void mtable() =0;
};
class derived:public base{
public:
    int a,b;
    void input(){
        cin>>a;
    }
    void mtable(){
        int i,t;
        t=a;
        for (i=0;i<5;i++){
            cout<<t<<" ";
            t=t+a;
        }
        }
};
int main(){
    base *b;
    derived d;
    b=&d;
    d.input();
    d.mtable();
    
    return 0;
}
