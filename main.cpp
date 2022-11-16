#include <iostream>

using namespace std;

class Shape
{
protected:
    float dimx;
    float dimy;

public:
    Shape()
    {
        dimx = 0;
        dimy = 0;
    };
    Shape(float _x, float _y)
    {
        dimx = _x;
        dimy = _y;
    }
    ~Shape(){}

    virtual float Area()=0;

    //void setDimx(float _x){dimx = _x;}
    //void setDimy(float _y){dimy = _y;}

    float getDimx(){return dimx;}
    float getDimy(){return dimy;}
};

class Triangle: public Shape
{
public:
    Triangle(){}
    Triangle(float _x, float _y):Shape(_x, _y){}
    ~Triangle(){}

    float Area()
    {
        return 0.5 * dimx * dimy;
    }
};

class Circle: public Shape
{
public:
    Circle(){}
    Circle(float _x):Shape(_x, _x){}
    ~Circle(){}

    float Area()
    {
        return 3.14 * dimx * dimy;
    }
};

class Rect: public Shape
{
public:
    Rect(){}
    Rect(float _x, float _y):Shape(_x, _y){}
    ~Rect(){}

    float Area()
    {
        return dimx * dimy;
    }
};

class Square: public Rect
{
public:
    Square(){}
    Square(float _x): Rect(_x, _x){}
    ~Square(){}
};

float sumOfArea(Shape** param, int _size)
{
    float sum = 0;

    for(int i=0; i<_size; i++)
    {
        sum += param[i]->Area();
    }

    return sum;
}

int main()
{
    //Shape s;

    Rect r(5, 6);
    Square sq(4);
    Circle c(3);
    Triangle t(4, 6);

    Shape* sptr[4] = {&r, &sq, &c, &t};

    cout << "the sum of area of all shapes is: ";
    cout << sumOfArea(sptr, 4) <<endl;

    cout << "_____________________" << endl;

    cout << "Area of Rect" << endl;
    cout << r.Area() << endl;

    cout << "Area of Square" << endl;
    cout << sq.Area() << endl;

    cout << "Area of Circle" << endl;
    cout << c.Area() << endl;

    cout << "Area of Triangle" << endl;
    cout << t.Area() << endl;



    return 0;
}

