#include<iostream>
#include<set>
#include<functional>

using namespace std;
class Person{
    public:
    int age;
    string name;
    // bool operator < (const Person &rhs) const { return age<rhs.age; }
    bool operator > (const Person &rhs) const { return age>rhs.age; }
};
int main()
{
    // set <int , greater<>> s1 = {1,2,3,5,4,6,2,1,3,6,5,4};
    set <Person, greater<>> p1 = {{17, "Parth"}, {23, "Raju"}, {11, "Darshan"}};
    for(const auto & x: p1)
        cout<<x.age<<" "<<x.name<<endl;
}
