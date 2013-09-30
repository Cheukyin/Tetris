#ifndef OPERATOR_H
#define OPERATOR_H

class Coord
{
public:
    int x;
    int y;
    Coord();
    Coord(int a1,int a2);
};

class Matrix_2nd_Order
{
private:
    int a[2][2];
public:
    Matrix_2nd_Order();
    Matrix_2nd_Order(int a11,int a12,int a21,int a22);
    Coord operator*(const Coord *t) const;
};

#endif // OPERATOR_H
