//
//  ShapeVirtual.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 12/10/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;
class Shape
{
public:
    int x;
    void getData()
    {
        cin>>x;
    }
    virtual float calculateArea()
    {
        return 0;
    }
};
class Square: public Shape
{
public:
    float calculateArea()
    {
        return x*x;
    }
};
class Circle: public Shape
{
public:
    float calculateArea()
    {
        return 3.14*x*x;
    }
};
int main()
{
    Shape *p;
    Square s;
    Circle c;
    p=&s;
    cout << "Enter length to calculate the area of a square: ";
    p->getData();
    cout<<"Area of square: " << p->calculateArea();
    p=&c;
    cout<<"\nEnter radius to calculate the area of a circle: ";
    p->getData();
    cout << "Area of circle: " << p->calculateArea()<<endl;
    return 0;
}
