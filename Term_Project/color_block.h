//
// Created by 민윤기 on 2019/11/28.
//

#ifndef OOPTERMTEMP_COLOR_BLOCK_H
#define OOPTERMTEMP_COLOR_BLOCK_H

#include <set>
#include "block.h"

using namespace std;

class color_block {
private:
    set<block *> s;
public:
    color_block(block *b);

    void insert(set<block *> s);

    set<block *> get_set();

    int get_set_size();
};


#endif //OOPTERMTEMP_COLOR_BLOCK_H
