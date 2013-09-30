#ifndef BLOCK_H
#define BLOCK_H

#define LEFT 0
#define RIGHT 1
#define QUICK_DOWN 2
#define SLOW_DOWN 3
#define ROTATE 4

class Coord;
class Matrix_2nd_Order;

class BLOCK
{
private:
    Coord *block_coord[4];
    Coord *block_coord_tmp[4];
    Matrix_2nd_Order *rot_matrix;
    Coord *cylinder_coord[4];
    int shape_num;
    int shape_num_tmp;
    int scr_cylinder_left;

public:
    BLOCK();
    void Rotate();
    void Rotate_tmp();
    void Random_Shape();
    void init_cylinder();
    void get_cylinder(Coord *) const;
    void move(int direction);
    int left_most() const;
    int bottom_most() const;
    void clr_src_right();
    void tmp2block();
    void get_predict(Coord *t) const;
};

#endif // BLOCK_H
