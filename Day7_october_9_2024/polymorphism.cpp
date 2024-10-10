#include<bits/stdc++.h>
using namespace std;

class Shape{
    public:
    virtual void draw()
    {
        cout << "drawing a shape" << endl;
    }
};

class Square : public Shape
{
    public:
    void draw()
    {
        cout << "Drawing a square" << endl;
    }
};

class Circle : public Shape
{
    public:
    void draw() 
    {
        cout << "drawing a circle" << endl;
    }
};

void draw_shape(Shape * shape)
{
    shape->draw();
}
int main()
{
    Circle circle;
    Square square;

    draw_shape(&circle);
    draw_shape(&square);

    Shape *s1 = &circle;
    s1->draw();

    return 0;
}