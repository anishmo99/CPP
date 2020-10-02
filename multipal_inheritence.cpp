#include<cstring>
#include<iostream>
using namespace std;
class surname
{
    char s[20];
public:
    set_surname(){
        cout<<"Enter surname : ";
        cin>>s;
    }
    char* get_surname(){ return s; }
};
class name
{
    char n[20];
public:
    set_name(){
        cout<<"Enter name : ";
        cin>>n;
    }
    char* get_name() { return n; }
};
class full_name : public surname, public name
{
    char full_name[50];
public:
    void get_data(){
        set_surname();
        set_name();
        strcpy(full_name,get_surname());
        strcat(full_name," ");
        strcat(full_name,get_name());
    }
    void display_data(){
        cout<<"Your Full name is : "<<full_name<<endl;
    }
};
int main()
{
    int n;
    cout<<"Enter number of student : ";
    cin>>n;

    full_name *f = new full_name[n];
    for(int i=0; i<n; i++)
        f[i].get_data();
    for(int j=0; j<n; j++)
        f[j].display_data();
}
