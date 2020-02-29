//
// Created by 김혁진 on 2019/12/11.
//

#include "fold_block.h"
#include "../board.h"

fold_block::fold_block(int center_x, int center_y, int c1, int c2, int c3) {
    block_vector.push_back(new block(center_x, center_y, c1));      // center
    block_vector.push_back(new block(center_x-1, center_y, c2)); // left
    block_vector.push_back(new block(center_x, center_y+1, c3)); // top
}

fold_block::~fold_block() {}

bool fold_block::can_left() {
    if (block_vector[0]->same_x(block_vector[2])) {
        if (block_vector[0]->get_x() < block_vector[1]->get_x()) {
            if (!block_vector[0]->can_left())
                return false;

            return block_vector[2]->can_left();
        } else {
            if (!block_vector[1]->can_left())
                return false;

            return block_vector[2]->can_left();
        }
    } else {
        if (block_vector[0]->get_x() < block_vector[2]->get_x()) {
            if (!block_vector[0]->can_left())
                return false;

            return block_vector[1]->can_left();
        } else {
            if (!block_vector[1]->can_left())
                return false;

            return block_vector[2]->can_left();
        }
    }
}

bool fold_block::can_right() {
    if (block_vector[0]->same_x(block_vector[2])) {
        if (block_vector[0]->get_x() < block_vector[1]->get_x()) {
            if (!block_vector[1]->can_right())
                return false;

            return block_vector[2]->can_right();
        } else {
            if (!block_vector[0]->can_right())
                return false;

            return block_vector[2]->can_right();
        }
    } else {
        if (block_vector[0]->get_x() < block_vector[2]->get_x()) {
            if (!block_vector[1]->can_right())
                return false;

            return block_vector[2]->can_right();
        } else {
            if (!block_vector[0]->can_right())
                return false;

            return block_vector[1]->can_right();
        }
    }
}

bool fold_block::can_down() {
    if (block_vector[0]->same_y(block_vector[2])) {
        if (block_vector[0]->get_y() < block_vector[1]->get_y()) {
            if (!block_vector[0]->can_down())
                return false;

            return block_vector[2]->can_down();
        } else {
            if (!block_vector[1]->can_down())
                return false;

            return block_vector[2]->can_down();
        }
    } else {
        if (block_vector[0]->get_y() < block_vector[2]->get_y()) {
            if (!block_vector[0]->can_down())
                return false;

            return block_vector[1]->can_down();
        } else {
            if (!block_vector[1]->can_down())
                return false;

            return block_vector[2]->can_down();
        }
    }
}

bool fold_block::can_rotate() {
    if (block_vector[0]->get_x() == block_vector[2]->get_x()) {
        if (block_vector[0]->get_x() > block_vector[1]->get_x())
            return board::puyo_board.can_move(block_vector[0]->get_x()+1, block_vector[0]->get_y());
        else
            return board::puyo_board.can_move(block_vector[0]->get_x()-1, block_vector[0]->get_y());
    }

    if (block_vector[0]->get_x() > block_vector[2]->get_x())
        return board::puyo_board.can_move(block_vector[0]->get_x(), block_vector[0]->get_y()+1);
    else
        return board::puyo_board.can_move(block_vector[0]->get_x(), block_vector[0]->get_y()-1);
}

void fold_block::left() {
    if (block_vector[0]->same_x(block_vector[2])) {
        if (block_vector[0]->get_x() < block_vector[1]->get_x()) {
            block_vector[0]->left();
            block_vector[1]->left();
            block_vector[2]->left();
        } else {
            block_vector[1]->left();
            block_vector[0]->left();
            block_vector[2]->left();
        }
    } else {
        if (block_vector[0]->get_x() < block_vector[2]->get_x()) {
            block_vector[0]->left();
            block_vector[1]->left();
            block_vector[2]->left();
        } else {
            block_vector[2]->left();
            block_vector[0]->left();
            block_vector[1]->left();
        }
    }
}

void fold_block::right() {
    if (block_vector[0]->same_x(block_vector[2])) {
        if (block_vector[0]->get_x() < block_vector[1]->get_x()) {
            block_vector[1]->right();
            block_vector[0]->right();
            block_vector[2]->right();
        } else {
            block_vector[0]->right();
            block_vector[1]->right();
            block_vector[2]->right();
        }
    } else {
        if (block_vector[0]->get_x() < block_vector[2]->get_x()) {
            block_vector[2]->right();
            block_vector[0]->right();
            block_vector[1]->right();
        } else {
            block_vector[0]->right();
            block_vector[1]->right();
            block_vector[2]->right();
        }
    }
}

void fold_block::down() {
    if (block_vector[0]->same_y(block_vector[2])) {
        if (block_vector[0]->get_y() < block_vector[1]->get_y()) {
            block_vector[0]->down();
            block_vector[1]->down();
            block_vector[2]->down();
        } else {
            block_vector[1]->down();
            block_vector[0]->down();
            block_vector[2]->down();
        }
    } else {
        if (block_vector[0]->get_y() < block_vector[2]->get_y()) {
            block_vector[0]->down();
            block_vector[1]->down();
            block_vector[2]->down();
        } else {
            block_vector[2]->down();
            block_vector[0]->down();
            block_vector[1]->down();
        }
    }
}

void fold_block::drop() {
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

void fold_block::rotate() {
    int temp_x = block_vector[2]->get_x();
    int temp_y = block_vector[2]->get_y();

    if (block_vector[0]->get_x() == block_vector[2]->get_x()) {
        if (block_vector[0]->get_x() > block_vector[1]->get_x())
            block_vector[2]->move(block_vector[0]->get_x()+1, block_vector[0]->get_y());
        else
            block_vector[2]->move(block_vector[0]->get_x()-1, block_vector[0]->get_y());
    } else {
        if (block_vector[0]->get_x() > block_vector[2]->get_x())
            block_vector[2]->move(block_vector[0]->get_x(), block_vector[0]->get_y() + 1);
        else
            block_vector[2]->move(block_vector[0]->get_x(), block_vector[0]->get_y() - 1);
    }

    block_vector[1]->move(temp_x, temp_y);
}

void fold_block::make() {
    for (int i = 0; i < block_vector.size(); ++i) {
        block_vector[i]->make();
    }
}

void fold_block::merge() {
    board::puyo_board.merge(block_vector[0]);
    board::puyo_board.merge(block_vector[1]);
    board::puyo_board.merge(block_vector[2]);
}
