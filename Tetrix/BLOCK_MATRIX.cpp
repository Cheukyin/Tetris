#include <BLOCK_MATRIX.h>
#include <OPERATOR.h>

BLOCK_MATRIX::BLOCK_MATRIX()
{
    for(int i=0;i<=23;i++)
        for(int j=0;j<=11;j++)
            a[i][j]=false;
    highest_line=-1;
}

void BLOCK_MATRIX::clear()
{
    for(int i=0;i<=23;i++)
        for(int j=0;j<=11;j++)
            a[i][j]=false;
    highest_line=-1;
}

void BLOCK_MATRIX::set_block(Coord *t)
{
    for(int i=0;i<=3;i++)
        a[t[i].y][t[i].x]=true;
}

void BLOCK_MATRIX::set_highest(Coord *t)
{
    for(int i=0;i<=3;i++)
        if(highest_line<t[i].y)
            highest_line=t[i].y;
}

int BLOCK_MATRIX::destroy_lines(int starting_point,int end_point)
{
    int sum=-1;
    int u[5]={-1,-1,-1,-1,-1};

    for(int i=starting_point;i<=end_point;i++)
        if(is_LineFull(i))
        {
            sum++;
            u[sum]=i;
        }
    u[sum+1]=highest_line+3;

    switch(sum)
    {
    case 0:
        for(int e=u[0]+1;e<=u[1];e++)
            for(int l=0;l<=11;l++)
                a[e-1][l]=a[e][l];
        break;
    case 1:
        if(u[0]!=u[1]-1)
            for(int e=u[0]+1;e<=u[1]-1;e++)
                for(int l=0;l<=11;l++)
                    a[e-1][l]=a[e][l];
        for(int e=u[1]+1;e<=u[2];e++)
            for(int l=0;l<=11;l++)
                a[e-2][l]=a[e][l];
        break;
    case 2:
        if(u[0]!=u[1]-1)
            for(int e=u[0]+1;e<=u[1]-1;e++)
                for(int l=0;l<=11;l++)
                    a[e-1][l]=a[e][l];
        if(u[1]!=u[2]-1)
            for(int e=u[1]+1;e<=u[2]-1;e++)
                for(int l=0;l<=11;l++)
                    a[e-2][l]=a[e][l];
        for(int e=u[2]+1;e<=u[3];e++)
            for(int l=0;l<=11;l++)
                a[e-3][l]=a[e][l];
        break;
    case 3:
        for(int e=0;e<=11;e++)
            a[u[3]][e]=false;
        for(int e=u[3]+1;e<=u[4];e++)
            for(int l=0;l<=11;l++)
                a[e-4][l]=a[e][l];
        for(int l=0;l<=11;l++)
            a[highest_line][l]=false;
        break;
    defalut:break;
    }

    return (sum+1);
}

bool BLOCK_MATRIX::is_LineFull(int level)
{
    for(int i=0;i<=11;i++)
        if(!a[level][i])
            return false;
    return true;
}
