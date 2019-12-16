//
// Created by 민윤기 on 2019/11/28.
//
#include "big_block.h"


big_block::big_block(int type) {
    rotation = 0;
    this->types = type;
    gx = 2, gy = 3;
}

big_block::~big_block() {
    while (!v.empty())
        v.pop_back();
}

bool big_block::can_left() {
    for (block *b : v) {
        if (!b->can_left())
            return false;
    }
    return true;
}

bool big_block::can_right() {
    for (block *b : v) {
        if (!b->can_right())
            return false;
    }
    return true;
}

bool big_block::can_down() {
    for (block *b : v) {
        if (!b->can_down())
            return false;
    }
    return true;
}

void big_block::left() {
    for (block *b : v)
        array_2d::delete_block(b->get_x(), b->get_y());
    for (block *b : v)
        b->left();
    gy -= 1;
}

void big_block::right() {
    for (block *b : v)
        array_2d::delete_block(b->get_x(), b->get_y());
    for (block *b : v)
        b->right();
    gy += 1;
}

void big_block::down() {
    for (block *b : v)
        array_2d::delete_block(b->get_x(), b->get_y());
    for (block *b : v)
        b->down();
    gx += 1;
}

void big_block::down_all() {
    if (types == 0)
        gx = v[1]->get_x();
    else if (types == 1)
        gx = v[1]->get_x();
    else if (types == 2)
        gx = v[2]->get_x();

    for (block *b : v) {
        b->down_all(false);
    }
}

void big_block::rotated(int &x, int &y) {
    int new_x = (y - gy) * -1;
    int new_y = (x - gx);
    x = new_x + gx;
    y = new_y + gy;
}

bool big_block::move(int input) {
    if (input == 0 && can_left()) {
        left();
        return true;
    } else if (input == 1 && can_right()) {
        right();
        return true;
    } else if (input == 2 && can_down()) {
        down();
        return true;
    }
    return false;
}

bool big_block::can_rotate() {
    int temp_x, temp_y;
    for (block *b : v) {
        temp_x = b->get_x();
        temp_y = b->get_y();
        rotated(temp_x, temp_y);
        block *nb = array_2d::get_block(temp_x, temp_y);
        if (nb != nullptr && nb->is_located())
            return false;
    }
    return true;
}


void big_block::rotate() {
    if (!can_rotate())
        return;
    for (block *b : v)
        array_2d::delete_block(b->get_x(), b->get_y());

    int x, y;
    for (block *b : v) {
        x = b->get_x();
        y = b->get_y();
        rotated(x, y);
        b->set_location(x, y);
    }

    rotation += 1;
    if (rotation == 2 || rotation == 4) {
        vector<block *> new_v = vector<block *>(v.size(), nullptr);
        for (int i = 0; i < v.size(); i++)
            new_v[v.size() - i - 1] = v[i];
        v = new_v;

        if (rotation == 4)
            rotation = 0;
    }


}
