//
// Created by 김혁진 on 2019/12/11.
//

#ifndef PUYO_TREE_BLOCK_H
#define PUYO_TREE_BLOCK_H

#include "shape_block.h"

class tree_block : public shape_block {
public:
    tree_block(int center_x, int center_y, int c1, int c2, int c3);
    ~tree_block();

    bool can_left();
    bool can_right();
    bool can_down();
    bool can_rotate();

    void left();
    void right();
    void down();
    void drop();
    void rotate();

    void make();
    void merge();
};

#endif // PUYO_TREE_BLOCK_H
