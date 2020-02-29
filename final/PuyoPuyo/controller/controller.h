//
// Created by 김혁진 on 2019/12/11.
//

#ifndef PUYO_CONTROLLER_H
#define PUYO_CONTROLLER_H

#include <cstdlib>
#include <iostream>

#include "../puyo/board.h"
#include "../puyo/shape_block/shape_block.h"

class controller {
private:
    int count;
    shape_block* current_block;

    void make_block();

    void left();
    void right();
    void down();
    void drop();
    void rotate();
    void explode();

    bool can_move();
    void move();
    static void print();
public:
    controller();

    void start();
};

#endif // PUYO_CONTROLLER_H
