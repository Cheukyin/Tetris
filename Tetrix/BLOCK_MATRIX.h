#ifndef BLOCK_MATRIX_H
#define BLOCK_MATRIX_H

class Coord;

class BLOCK_MATRIX
{
public:
    bool   a[24][12];
    int highest_line;

    BLOCK_MATRIX();
    void set_block(Coord *t);
    void set_highest(Coord *t);
    bool is_LineFull(int level);
    int destroy_lines(int starting_point,int end_point);
    void clear();
};

#endif // BLOCK_MATRIX_H
