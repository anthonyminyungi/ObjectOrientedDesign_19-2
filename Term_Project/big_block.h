//
// Created by 민윤기 on 2019/11/28.
//

#ifndef OOPTERMTEMP_BIG_BLOCK_H
#define OOPTERMTEMP_BIG_BLOCK_H

#include "array_2d.h"
#include "block.h"
#include <vector>

using namespace std;

class big_block {
private:
    int rotation, gx, gy ,types;

    void left();

    void right();

    void down();

    bool can_left();

    bool can_right();

    void rotated(int &x, int &y);

    bool can_rotate();

protected:
    vector<block *> v;

public:
    big_block(int type);

    bool move(int input);

    void rotate();

    bool can_down();

    ~big_block();

    void down_all();


};


#endif //OOPTERMTEMP_BIG_BLOCK_H
