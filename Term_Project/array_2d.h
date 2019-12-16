//
// Created by 민윤기 on 2019/11/28.
//

#ifndef OOPTERMTEMP_ARRAY_2D_H
#define OOPTERMTEMP_ARRAY_2D_H

#include "color_block.h"
#include <set>
#include <vector>

using namespace std;
const int H = 14;
const int W = 7;

class array_2d {
private:
    static int expc;
    static int score;
    static block *block_array[H][W];
    static set<color_block *> explosion_s;

    static void remove_explosion();

    static void insert_explosion(color_block *group);

    static void is_gray_block(int new_x, int new_y);


public:
    static int explosion(int &exp);

    static bool can_make(int types);

    array_2d();

    static void print();

    static int get_score();

    static void down_all();

    static void insert(vector<block *> v);

    static void insert(int x, int y, block *b);

    static block *get_block(int x, int y);

    static void delete_block(int x, int y);

};


#endif //OOPTERMTEMP_ARRAY_2D_H
