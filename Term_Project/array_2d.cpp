//
// Created by 민윤기 on 2019/11/28.
//

#include <iostream>
#include "block.h"
#include "array_2d.h"
#include "color_block.h"


block *array_2d::block_array[H][W];
set<color_block *> array_2d::explosion_s;
int array_2d::score = 0;
int array_2d::expc = 0;

array_2d::array_2d() {
    expc = 0;
    score = 0;
    explosion_s = set<color_block *>();

    for (int i = 1; i < H - 1; i++) {
        for (int j = 1; j < W - 1; j++)
            block_array[i][j] = nullptr;
    }
    for (int i = 0; i < W; i++) {
        block_array[0][i] = new block(0);
        block_array[H - 1][i] = new block(0);
        block_array[0][i]->fix_location(true);
        block_array[H - 1][i]->fix_location(true);
        block_array[0][i]->set_location(0, i);
        block_array[H - 1][i]->set_location(H - 1, i);
    }

    for (int i = 0; i < H; i++) {
        block_array[i][0] = new block(0);
        block_array[i][W - 1] = new block(0);
        block_array[i][0]->fix_location(true);
        block_array[i][W - 1]->fix_location(true);
        block_array[i][0]->set_location(i, 0);
        block_array[i][W - 1]->set_location(i, W - 1);
    }
}

bool array_2d::can_make(int types) {
    if (types == 0 && (block_array[1][3] != nullptr || block_array[2][3] != nullptr || block_array[2][2] != nullptr))
        return false;

    else if (types == 1 &&
             (block_array[1][3] != nullptr || block_array[2][3] != nullptr || block_array[3][3] != nullptr))
        return false;

    else if (types == 2 &&
             (block_array[1][3] != nullptr || block_array[2][2] != nullptr || block_array[2][3] != nullptr ||
              block_array[2][4] != nullptr || block_array[3][3] != nullptr))
        return false;


    return true;
}

int array_2d::get_score() { return score; }

block *array_2d::get_block(int x, int y) {
    if (x >= 0 && y >= 0 && x < H && y < W)
        return block_array[x][y];
    else
        return nullptr;
}


void array_2d::insert_explosion(color_block *group) {
    auto it = explosion_s.find(group);

    if (it == explosion_s.end())
        explosion_s.insert(group);
}

void array_2d::remove_explosion() {
    for (color_block *group : explosion_s)
        if (group) {
            delete (group);
            group = nullptr;
        }

    explosion_s = set<color_block *>();
}

void array_2d::print() {
    cout << "Score : " << score << "\n";
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (block_array[i][j] == nullptr)
                cout << "   ";
            else {
                int col = block_array[i][j]->get_color();
                cout << " " << col << " ";
            }

        }
        cout << "\n";
    }
}


void array_2d::insert(vector<block *> v) {
    int new_x, new_y;
    for (block *b : v) {
        new_x = b->get_x();
        new_y = b->get_y();
        block_array[new_x][new_y] = b;
    }

    if (expc > 0) {
        score += expc;
        expc = 0;
    }
}

void array_2d::insert(int x, int y, block *b) {
    block_array[x][y] = b;
}

void array_2d::delete_block(int x, int y) {
    block_array[x][y] = nullptr;
}


void array_2d::down_all() {
    for (int i = H - 2; i > 0; i--) {
        for (int j = 1; j < W - 1; j++) {
            if (block_array[i][j] == nullptr)
                continue;
            block_array[i][j]->down_all(true);
        }
    }

    int temp;
    for (int i = H - 2; i > 0; i--) {
        temp = 0;
        for (int j = 1; j < W - 1; j++) {
            if (block_array[i][j] == nullptr) {
                temp += 1;
                continue;
            }
            if (block_array[i][j]->can_explosion())
                insert_explosion(block_array[i][j]->get_group());
        }
        if (temp == W - 2)
            break;
    }
}

int array_2d::explosion(int &exp) {
    int new_x, new_y, color;
    int forx[4] = {1, -1, 0, 0};
    int fory[4] = {0, 0, 1, -1};

    bool isexplode = false;
    for (color_block *blocks : explosion_s) {
        ++exp;
        for (block *b : blocks->get_set()) {
            for (int i = 0; i < 4; i++) {
                color = 5;
                new_x = forx[i] + b->get_x();
                new_y = fory[i] + b->get_y();
                if (block_array[new_x][new_y] != nullptr)
                    color = block_array[new_x][new_y]->get_color();
                if (color == 1) {
                    is_gray_block(new_x, new_y);
                }
            }
            block_array[b->get_x()][b->get_y()] = nullptr;
            delete (b);
            b = nullptr;
        }
        isexplode = true;
        expc++;
    }
    if (isexplode)
        remove_explosion();
    else
        exp = 0;

    return exp;
}

void array_2d::is_gray_block(int new_x, int new_y) {
    if (block_array[new_x][new_y] != nullptr && block_array[new_x][new_y]->get_color() == 1) {
        if (block_array[new_x][new_y]) {
            delete (block_array[new_x][new_y]);
            block_array[new_x][new_y] = nullptr;
        }
        is_gray_block(new_x + 1, new_y);
        is_gray_block(new_x - 1, new_y);
        is_gray_block(new_x, new_y + 1);
        is_gray_block(new_x, new_y - 1);
    } else
        return;
}
