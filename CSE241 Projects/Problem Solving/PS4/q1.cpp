#include <iostream>
#include <cstdlib>

using namespace std;

class Vector2D
{
    public:
        Vector2D();
        Vector2D(int newx, int newy);
        void SetXY(int newx, int newy);
        int GetX();
        int GetY();
        int operator *(const Vector2D &v2);
    
    private:
        int x,y;
};


Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}

Vector2D::Vector2D(int newx, int newy)
{
    x = newx;
    y = newy;
}

void Vector2D::SetXY(int newx, int newy)
{
    x=newx;
    y=newy;
}

int Vector2D::GetX()
{
    return (x);
}

int Vector2D::GetY()
{
    return (y);
}

int Vector2D::operator*(const Vector2D &v2)
{
    return((this->x*v2.x) + (this->y*v2.y));
}

int main()
{

    Vector2D v1(10,21), v2(4,10), v3(11,15) , v4(6,3);

    cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX()
        << "," << v2.GetY() << ") = " << v1*v2 << endl;
    cout << "(" << v2.GetX() << "," << v2.GetY() << ") * (" << v3.GetX()
        << "," << v3.GetY() << ") = " << v2*v3 << endl;
    cout << "(" << v3.GetX() << "," << v3.GetY() << ") * (" << v4.GetX()
        << "," << v4.GetY() << ") = " << v3*v4 << endl;

    return 0;
}