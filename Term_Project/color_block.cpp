//
// Created by 민윤기 on 2019/11/28.
//

#include "color_block.h"
#include "block.h"

color_block::color_block(block *b) {
    s = set<block *>();
    if (b != nullptr)
        s.insert(b);
}

void color_block::insert(set<block *> blocks) {
    for (block *b : blocks) {
        b->set_group(this);
        s.insert(b);
    }
}

set<block *> color_block::get_set() {
    return s;
}


int color_block::get_set_size() {
    return s.size();
}

