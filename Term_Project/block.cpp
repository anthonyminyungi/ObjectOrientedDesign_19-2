//
// Created by 민윤기 on 2019/11/28.
//

#include "block.h"
#include "array_2d.h"
#include "color_block.h"

block::block(int color) {
    located = false;
    x = 0, y = 0;
    this->color = color;
    group = new color_block(this);
}

void block::set_location(int x, int y) {
    this->x = x, this->y = y;
    array_2d::insert(x, y, this);
}

void block::right() {
    y += 1;
    array_2d::insert(x, y, this);
}

void block::left() {
    y -= 1;
    array_2d::insert(x, y, this);
}

void block::down() {
    x += 1;
    array_2d::insert(x, y, this);
}

bool block::can_down() {
    return array_2d::get_block(x + 1, y) == nullptr || !array_2d::get_block(x + 1, y)->is_located();
}

bool block::can_left() {
    return array_2d::get_block(x, y - 1) == nullptr || !array_2d::get_block(x, y - 1)->is_located();
}

bool block::can_right() {
    return array_2d::get_block(x, y + 1) == nullptr || !array_2d::get_block(x, y + 1)->is_located();
}


int block::get_color() {
    return color;
}

int block::get_x() {
    return x;
}

int block::get_y() {
    return y;
}

bool block::is_located() {
    return located;
}

color_block *block::get_group() {
    return group;
}

void block::fix_location(bool located) {
    this->located = located;
}

void block::set_group(color_block *group) {
    this->group = group;
}


bool block::can_explosion() {
    return group->get_set_size() >= 4;
}

bool block::can_merge(block *b) {
    if (b->color == 0 || b->color == 1)
        return false;

    set<block *> tmp = group->get_set();
    auto it = tmp.find(b);

    return it == tmp.end() && b->color == color;
}


int forx[4] = {1, -1, 0, 0};
int fory[4] = {0, 0, 1, -1};


void block::find_merge() {
    int temp = 0;
    for (int i = 0; i < 4; i++) {
        int new_x = x + forx[i];
        int new_y = y + fory[i];
        block *b = array_2d::get_block(new_x, new_y);
        if (b != nullptr && can_merge(b)) {
            merge(b);
            ++temp;
        }
    }
}


void block::down_all(bool down) {
    array_2d::delete_block(x, y);

    if (can_down() && down) {
        x += 1;
        set<block *> g = group->get_set();
        auto it = g.find(this);
        if (it != g.end())
            g.erase(it);
        group = nullptr;
        group = new color_block(this);
    }
    while (can_down())
        x += 1;
    located = true;
    array_2d::insert(x, y, this);
    if (down) find_merge();
}

void block::merge(block *b) {
    auto *nb = new color_block(nullptr);
    color_block *bg = b->get_group();
    color_block *tg = group;
    nb->insert(bg->get_set());
    nb->insert(tg->get_set());
    delete (bg);
    bg = nullptr;
    delete (tg);
    tg = nullptr;
}