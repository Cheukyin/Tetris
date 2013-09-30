#include <OPERATOR.h>

Coord::Coord()
{
    x=0;
    y=0;
}

Coord::Coord(int a1,int a2)
{
    x=a1;
    y=a2;
}

Matrix_2nd_Order::Matrix_2nd_Order()
{
}

Matrix_2nd_Order::Matrix_2nd_Order(int a11, int a12, int a21, int a22)
{
    a[0][0]=a11;
    a[0][1]=a12;
    a[1][0]=a21;
    a[1][1]=a22;
}

Coord Matrix_2nd_Order::operator *(const Coord * t) const
{
   Coord result;
   result.x=a[0][0]*t->x+a[0][1]*t->y;
   result.y=a[1][0]*t->x+a[1][1]*t->y;
   return result;
}
