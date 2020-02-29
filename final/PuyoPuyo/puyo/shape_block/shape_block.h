//
// Created by 김혁진 on 2019/12/11.
//

#ifndef PUYO_SHAPE_BLOCK_H
#define PUYO_SHAPE_BLOCK_H

#include <vector>
#include "block/block.h"

using std::vector;

class shape_block {
protected:
    vector<block*> block_vector;

public:
    virtual ~shape_block(){}

    virtual bool can_left() = 0;
    virtual bool can_right() = 0;
    virtual bool can_down() = 0;
    virtual bool can_rotate() = 0;

    virtual void left() = 0;
    virtual void right() = 0;
    virtual void down() = 0;
    virtual void drop() = 0;

    virtual void rotate() = 0;

    virtual void make() = 0;
    virtual void merge() = 0;
};

#endif // PUYO_SHAPE_BLOCK_H
