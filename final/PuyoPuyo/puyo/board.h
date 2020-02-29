//
// Created by 김혁진 on 2019/12/11.
//

#ifndef BOARD_H
#define BOARD_H

#define WIDTH 5
#define HEIGHT 12

#include <map>
#include <set>
#include <string>

#include "shape_block/block/block.h"
#include "shape_block/block/block_group.h"

using std::map;
using std::set;

class board {
private:
    block *block_array[HEIGHT][WIDTH];
    map<block*, block_group*> explosion_map;
    set<block_group*> block_groups;
    int score;

    void _merge(int a_x, int a_y, block* block);
    void merge_group(block * cur_block, block* adj_block);

    void drop();
    void merge_all();

    void explode_grey(int x, int y);
    void explode_adjacency_grey(int x, int y);
public:
    static int starting_x;
    static int starting_y;
    static board puyo_board;

    board();

    bool can_make(int type);
    bool can_move(int x, int y);
    bool is_block(int x, int y);

    void make(int x, int y, block* block);
    void merge(block* blk);
    void explode();

    void move_block(int old_x, int old_y, int new_x, int new_y);
    void explode_block(int x, int y);

    int get_score();
    std::string to_string();
};

#endif // BOARD_H
