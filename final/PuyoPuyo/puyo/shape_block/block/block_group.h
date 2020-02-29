//
// Created by 김혁진 on 2019/12/11.
//

#ifndef PUYO_BLOCK_GROUP_H
#define PUYO_BLOCK_GROUP_H

#include <set>
#include "block.h"

using std::set;

class block_group {
private:
    set<block*> block_set;
    int color;  // 0 : grey, 1 : red, 2 : green, 3 : blue

public:
    explicit block_group(block * block, int color);

    void insert(block* block);

    int get_size();
    int get_color();
    block * remove();
    int explosion();
};

#endif // PUYO_BLOCK_GROUP_H
