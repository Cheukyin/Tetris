#include <BLOCK.h>
#include <OPERATOR.h>
#include <QTime>

BLOCK::BLOCK()
{
    scr_cylinder_left=0;
    rot_matrix=new Matrix_2nd_Order(0,-1,1,0);
    for(int n=0;n<=3;n++)
        cylinder_coord[n]=new Coord(240,240);
    for(int n=0;n<=3;n++)
        block_coord[n]=new Coord;
}

void BLOCK::clr_src_right()
{
    scr_cylinder_left=0;
}

void BLOCK::Rotate_tmp()
{
    if(shape_num_tmp)
        for(int i=0;i<=3;i++)
            *block_coord_tmp[i]=(*rot_matrix)*block_coord_tmp[i];
}

void BLOCK::Rotate()
{
    int origin;
    if(shape_num)
    {
        for(int i=0;i<=3;i++)
            *block_coord[i]=(*rot_matrix)*block_coord[i];

        for(int i=0;i<=3;i++)
        {
                if(!block_coord[i]->x && !block_coord[i]->y)
                        origin=i;
        }

        int origin_x=cylinder_coord[origin]->x;
        int origin_y=cylinder_coord[origin]->y;

        for(int m=origin+1;m<=3;m++)
        {
                cylinder_coord[m]->x = (origin_x + block_coord[m]->x - block_coord[origin]->x)%12;
                cylinder_coord[m]->y = origin_y + block_coord[m]->y - block_coord[origin]->y;
        }

        for(int n=origin-1;n>=0;n--)
        {
        cylinder_coord[n]->x = (origin_x + block_coord[n]->x - block_coord[origin]->x)%12;
        cylinder_coord[n]->y = origin_y + block_coord[n]->y - block_coord[origin]->y;
        }
    }
}

void BLOCK::tmp2block()
{
    shape_num=shape_num_tmp;
    for(int n=0;n<=3;n++)
        *block_coord[n] = *block_coord_tmp[n];
}

void BLOCK::Random_Shape()
{

    int n;
    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    shape_num_tmp=qrand()%7;

    switch (shape_num_tmp) {
    case 0:                             //o
        block_coord_tmp[0]=new Coord(-1,1);
        block_coord_tmp[1]=new Coord(0,1);
        block_coord_tmp[2]=new Coord(0,0);
        block_coord_tmp[3]=new Coord(-1,0);
        break;
    case 1:                             //2
        block_coord_tmp[0]=new Coord(-1,1);
        block_coord_tmp[1]=new Coord(0,1);
        block_coord_tmp[2]=new Coord(0,0);
        block_coord_tmp[3]=new Coord(1,0);
        break;
    case 2:                             //s
        block_coord_tmp[0]=new Coord(0,1);
        block_coord_tmp[1]=new Coord(1,1);
        block_coord_tmp[2]=new Coord(-1,0);
        block_coord_tmp[3]=new Coord(0,0);
        break;
    case 3:                             //L
        block_coord_tmp[0]=new Coord(-1,1);
        block_coord_tmp[1]=new Coord(-1,0);
        block_coord_tmp[2]=new Coord(0,0);
        block_coord_tmp[3]=new Coord(1,0);
        break;
    case 4:                             //T
        block_coord_tmp[0]=new Coord(0,1);
        block_coord_tmp[1]=new Coord(-1,0);
        block_coord_tmp[2]=new Coord(0,0);
        block_coord_tmp[3]=new Coord(1,0);
        break;
    case 5:                             //J
        block_coord_tmp[0]=new Coord(1,1);
        block_coord_tmp[1]=new Coord(-1,0);
        block_coord_tmp[2]=new Coord(0,0);
        block_coord_tmp[3]=new Coord(1,0);
        break;
    case 6:                             //I
        block_coord_tmp[0]=new Coord(0,2);
        block_coord_tmp[1]=new Coord(0,1);
        block_coord_tmp[2]=new Coord(0,0);
        block_coord_tmp[3]=new Coord(0,-1);
        break;
    default:
        break;
    }

    n=qrand()%4;
    for(int i=1;i<=n;i++)
        Rotate_tmp();
}

int BLOCK::left_most() const
{
    int left=0;
    for(int i=1;i<=3;i++)
        if(block_coord[left]->x > block_coord[i]->x)
            left=i;

    return left;
}

int BLOCK::bottom_most() const
{
    int bottom=0;
    for(int i=1;i<=3;i++)
        if(block_coord[bottom]->y > block_coord[i]->y)
            bottom = i;

    return bottom;
}

void BLOCK::init_cylinder()
{
    int i,j;
    int left=left_most();
    i=cylinder_coord[left]->x = scr_cylinder_left;
    j=cylinder_coord[left]->y = 20 + block_coord[left]->y - block_coord[bottom_most()]->y;

    for(int m=left+1;m<=3;m++)
    {
        cylinder_coord[m]->x = (i + block_coord[m]->x - block_coord[left]->x)%12;
        cylinder_coord[m]->y = j + block_coord[m]->y - block_coord[left]->y;
    }

    for(int n=left-1;n>=0;n--)
    {
        cylinder_coord[n]->x = (i + block_coord[n]->x - block_coord[left]->x)%12;
        cylinder_coord[n]->y = j + block_coord[n]->y - block_coord[left]->y;
    }

}

void BLOCK::get_cylinder(Coord *t) const
{
    for(int n=0;n<=3;n++)
        t[n] = *cylinder_coord[n];

}

void BLOCK::get_predict(Coord *t) const
{
    for(int n=0;n<=3;n++)
        t[n] = *block_coord_tmp[n];
}

void BLOCK::move(int direction)
{
    if(direction==LEFT)
    {
        for(int n=0;n<=3;n++)
            cylinder_coord[n]->x ? (cylinder_coord[n]->x)-- : cylinder_coord[n]->x=11;
        scr_cylinder_left ? scr_cylinder_left-- : scr_cylinder_left=11;
    }

    else if(direction==RIGHT)
    {
        for(int n=0;n<=3;n++)
            (cylinder_coord[n]->x==11) ? cylinder_coord[n]->x=0 : (cylinder_coord[n]->x)++;
        (scr_cylinder_left==11) ? scr_cylinder_left=0 : scr_cylinder_left++;
    }

    else if(direction==SLOW_DOWN)
        for(int n=0;n<=3;n++)
            (cylinder_coord[n]->y)--;

    else if(direction==QUICK_DOWN)
        for(int n=0;n<=3;n++)
            (cylinder_coord[n]->y)-=5;
}
