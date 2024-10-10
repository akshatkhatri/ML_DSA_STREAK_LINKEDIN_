#include<bits/stdc++.h>
using namespace std;

class Room
{
    private:
        int length;
        int width;
    public:

    Room(int length, int width)
    {
        this->length = length;
        this->width = width;
    }

        friend void calc_area(Room r1);
};
void calc_area(Room r1)
{
    cout << "Area is " << r1.length * r1.width << endl;
}

int main()
{
    Room r1(5, 10);

    calc_area(r1);
}