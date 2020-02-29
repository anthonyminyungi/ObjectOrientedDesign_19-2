//
// Created by 김혁진 on 2019/12/11.
//

#include "controller.h"
#include "../puyo/shape_block/fold_block.h"
#include "../puyo/shape_block/tree_block.h"
#include "../puyo/shape_block/cross_block.h"

controller::controller()
  : current_block(nullptr) {
    std::srand(201950219); // 본인 학번을 적으세요.
    count = std::rand() % 3;
}

void controller::make_block() {
    int c1 = std::rand() % 4;
    int c2 = std::rand() % 4;
    int c3 = std::rand() % 4;
    if (count == 0) {
        current_block = new fold_block(board::starting_x, board::starting_y, c1, c2, c3);
    } else if (count == 1) {
        current_block = new tree_block(board::starting_x, board::starting_y, c1, c2, c3);
    } else {
        int c4 = std::rand() % 4;
        int c5 = std::rand() % 4;
        current_block = new cross_block(board::starting_x, board::starting_y, c1, c2, c3, c4, c5);
    }
    current_block->make();
}

void controller::left() {
    if (current_block->can_left())
        current_block->left();
}

void controller::right() {
    if (current_block->can_right())
        current_block->right();
}

void controller::down() {
    if (current_block->can_down())
        current_block->down();
}

void controller::rotate() {
    if (current_block->can_rotate())
        current_block->rotate();
}

void controller::drop() {
    current_block->drop();
    current_block->merge();
}

bool controller::can_move() {
    return current_block->can_down();
}

void controller::explode() {
    board::puyo_board.explode();
    if (current_block != nullptr)
        delete(current_block);
}

void controller::print() {
    std::cout << " Score : " << board::puyo_board.get_score() << std::endl;
    std::cout << board::puyo_board.to_string();
}

void controller::start() {
    while (board::puyo_board.can_make(count)) {
        make_block();
        move();
        explode();
        count = (count + 1) % 3;
    }
    std::cout << "\n Game Over... \n" << std::endl;
}

void controller::move() {
    while (can_move()) {
        print();
        char ch;
        std::cin >> ch;
        switch (ch) {
            case 'w':
                rotate();
                break;
            case 'a':
                left();
                break;
            case 's':
                down();
                break;
            case 'd':
                right();
                break;
            default:
                drop();
                break;
        }
    }
    drop();
}
