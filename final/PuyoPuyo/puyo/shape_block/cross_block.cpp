//
// Created by 김혁진 on 2019/12/11.
//

#include "cross_block.h"
#include "../board.h"

cross_block::cross_block(int center_x, int center_y, int c1, int c2, int c3, int c4, int c5) {
    block_vector.push_back(new block(center_x, center_y, c1));      // center
    block_vector.push_back(new block(center_x-1, center_y, c2)); // left
    block_vector.push_back(new block(center_x, center_y+1, c3)); // top
    block_vector.push_back(new block(center_x+1, center_y, c4)); // right
    block_vector.push_back(new block(center_x, center_y-1, c5)); // bottom
}

cross_block::~cross_block() {}

bool cross_block::can_left() {
    if (!block_vector[1]->can_left())
        return false;
    if (!block_vector[2]->can_left())
        return false;

    return block_vector[4]->can_left();
}

bool cross_block::can_right() {
    if (!block_vector[2]->can_right())
        return false;
    if (!block_vector[3]->can_right())
        return false;
    return block_vector[4]->can_right();
}

bool cross_block::can_down() {
    if (!block_vector[1]->can_down())
        return false;
    if (!block_vector[3]->can_down())
        return false;

    return block_vector[4]->can_down();
}

bool cross_block::can_rotate() {
    return true;
}

void cross_block::left() {
    block_vector[1]->left();
    block_vector[2]->left();
    block_vector[4]->left();
    block_vector[0]->left();
    block_vector[3]->left();
}

void cross_block::right() {
    block_vector[3]->right();
    block_vector[2]->right();
    block_vector[4]->right();
    block_vector[0]->right();
    block_vector[1]->right();
}

void cross_block::down() {
    block_vector[3]->down();
    block_vector[4]->down();
    block_vector[1]->down();
    block_vector[0]->down();
    block_vector[2]->down();
}

void cross_block::drop() {
    bool is_move = true;
    while (is_move) {
        is_move = false;
        for (int i = 0; i < block_vector.size(); ++i) {
            if (block_vector[i]->can_down()) {
                block_vector[i]->down();
                is_move = true;
            }
        }
    }
}

void cross_block::rotate() {
    block_vector[1]->change(block_vector[4]);
    block_vector[4]->change(block_vector[3]);
    block_vector[3]->change(block_vector[2]);
}

void cross_block::make() {
    for (int i = 0; i < block_vector.size(); ++i) {
        block_vector[i]->make();
    }
}

void cross_block::merge() {
    board::puyo_board.merge(block_vector[0]);
    board::puyo_board.merge(block_vector[1]);
    board::puyo_board.merge(block_vector[2]);
    board::puyo_board.merge(block_vector[3]);
    board::puyo_board.merge(block_vector[4]);
}

