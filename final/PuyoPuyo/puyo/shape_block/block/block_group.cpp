//
// Created by 김혁진 on 2019/12/11.
//

#include <iostream>
#include "block_group.h"
#include "../../board.h"

block_group::block_group(block * block, int color) : color(color) {
    block_set.insert(block);
}

int block_group::get_size() {
    return block_set.size();
}

void block_group::insert(block * block) {
    block_set.insert(block);
}

block *block_group::remove() {
    if (block_set.empty())
        return nullptr;

    block* block = *block_set.begin();
    block_set.erase(block_set.begin());
    return block;
}

int block_group::explosion() {
    int size = get_size();
    if (size < 4 || color == 0)
        return 0;

    for (set<block*>::iterator i = block_set.begin(); i != block_set.end(); ++i) {
        block* block = *i;
        board::puyo_board.explode_block(block->get_x(), block->get_y());
    }
    return size;
}

int block_group::get_color() {
    return color;
}
