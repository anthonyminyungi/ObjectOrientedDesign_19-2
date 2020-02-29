//
// Created by 김혁진 on 2019/12/11.
//

#include "block.h"
#include "../../board.h"

block::block(int x, int y, int color)
  : color(color),
    x(x),
    y(y) {}

int block::get_color() {
    return color;
}

int block::get_x() {
    return x;
}

int block::get_y() {
    return y;
}

bool block::can_left() {
    return board::puyo_board.can_move(x-1, y);
}

bool block::can_right() {
    return board::puyo_board.can_move(x+1, y);
}

bool block::can_down() {
    return board::puyo_board.can_move(x, y-1);
}

void block::move(int new_x, int new_y) {
    board::puyo_board.move_block(x, y, new_x, new_y);
    x = new_x;
    y = new_y;
}

void block::change(block * block) {
    if (block == nullptr)
        return;

    int t = color;
    color = block->color;
    block->color = t;
}

void block::make() {
    board::puyo_board.make(x, y, this);
}

void block::left() {
    move(x-1, y);
}

void block::right() {
    move(x+1, y);
}

void block::down() {
    move(x, y-1);
}

bool block::same_x(block *block) {
    return x == block->x;
}

bool block::same_y(block *block) {
    return y == block->y;
}

