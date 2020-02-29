//
// Created by 김혁진 on 2019/12/11.
//

#include <iostream>
#include "board.h"

board board::puyo_board;

int board::starting_x = 2;
int board::starting_y = 10;

board::board() : score(0) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            block_array[i][j] = nullptr;
        }
    }
}

bool board::can_make(int type) {
    switch (type) {
        case 0:  // fold block
            if (!can_move(starting_x, starting_y))
                return false;
            if (!can_move(starting_x-1, starting_y))
                return false;
            return can_move(starting_x, starting_y+1);
        case 1:  // tree block
            if (!can_move(starting_x, starting_y-1))
                return false;
            if (!can_move(starting_x, starting_y))
                return false;
            return can_move(starting_x, starting_y+1);
        case 2:  // cross block
            if (!can_move(starting_x, starting_y))
                return false;
            if (!can_move(starting_x-1, starting_y))
                return false;
            if (!can_move(starting_x, starting_y-1))
                return false;
            if (!can_move(starting_x+1, starting_y))
                return false;
            return can_move(starting_x, starting_y + 1);
        default:  // error
            return false;
    }
}

bool board::can_move(int x, int y) {
    return 0 <= x && x < WIDTH && 0 <= y && y < HEIGHT && block_array[y][x] == nullptr;
}

bool board::is_block(int x, int y) {
    return 0 <= x && x < WIDTH && 0 <= y && y < HEIGHT && block_array[y][x] != nullptr;
}

void board::make(int x, int y, block* block) {
    block_array[y][x] = block;
}

void board::merge_group(block * cur_block, block* adj_block) {
    block_group* group = explosion_map[adj_block];
    int size = group->get_size();
    for (int i = 0; i < size; ++i) {
        block* blk = group->remove();
        explosion_map[cur_block]->insert(blk);
        explosion_map[blk] = explosion_map[cur_block];
    }
    block_groups.erase(group);
}

void board::_merge(int a_x, int a_y, block *block) {
    if (is_block(a_x, a_y)) {
        if (block->get_color() == block_array[a_y][a_x]->get_color()) {
            if (explosion_map[block_array[a_y][a_x]] == nullptr)
                return;
            if (explosion_map[block] == explosion_map[block_array[a_y][a_x]])
                return;

            if (explosion_map[block_array[a_y][a_x]] != nullptr) {
                merge_group(block, block_array[a_y][a_x]);
            } else {
                explosion_map[block_array[a_y][a_x]] = explosion_map[block];
                explosion_map[block]->insert(block_array[a_y][a_x]);
            }
        }
    }
}

void board::merge(block* blk) {
    if (blk == nullptr || blk->get_color() == 0)
        return ;

    int x = blk->get_x();
    int y = blk->get_y();

    if (explosion_map[blk] == nullptr) {
        explosion_map[blk] = new block_group(blk, blk->get_color());
        block_groups.insert(explosion_map[blk]);
    }

    _merge(x-1, y, blk);
    _merge(x+1, y, blk);
    _merge(x, y-1, blk);
    _merge(x, y+1, blk);
}

void board::move_block(int old_x, int old_y, int new_x, int new_y) {
    if (block_array[old_y][old_x] == nullptr)
        return;

    block_array[new_y][new_x] = block_array[old_y][old_x];
    block_array[old_y][old_x] = nullptr;
}

void board::explode_grey(int x, int y) {
    if (is_block(x, y) && block_array[y][x]->get_color() == 0) {
        delete(block_array[y][x]);
        block_array[y][x] = nullptr;
    }
}

void board::explode_adjacency_grey(int x, int y) {
    explode_grey(x-1, y);
    explode_grey(x+1, y);
    explode_grey(x, y-1);
    explode_grey(x, y+1);
}

void board::explode_block(int x, int y) {
    explosion_map.erase(block_array[y][x]);
    delete(block_array[y][x]);
    block_array[y][x] = nullptr;
    explode_adjacency_grey(x, y);
}

void board::explode() {
    bool is_explode = false;
    for (set<block_group*>::iterator i = block_groups.begin(); i != block_groups.end();) {
        int size = (*i)->explosion();
        if (size != 0) {
            block_groups.erase(i++);
            score += size;
            is_explode = true;
        } else
            i++;
    }
    if (is_explode) {
        drop();
        merge_all();
        explode();
    }
}

void board::merge_all() {
    block_groups.clear();
    explosion_map.clear();
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            merge(block_array[i][j]);
        }
    }
}

void board::drop() {
    bool is_move = true;
    while (is_move) {
        is_move = false;
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                if (block_array[i][j] != nullptr && block_array[i][j]->can_down()) {
                    block_array[i][j]->down();
                    is_move = true;
                }
            }
        }
    }
}

int board::get_score() {
    return score;
}

std::string board::to_string() {
    std::string str;
    for (int i = HEIGHT-1; i >= 0; --i) {
        str += ' ';
        for (int j = 0; j < WIDTH; ++j) {
            if (block_array[i][j] == nullptr) {
                str += "\033[30;1m▢ \033[0m";
            } else if (block_array[i][j]->get_color() == 0) {  // grey
                str += "\033[37;1m▢ \033[0m";
            } else if (block_array[i][j]->get_color() == 1) {  // red
                str += "\033[31;1m▢ \033[0m";
            } else if (block_array[i][j]->get_color() == 2) {  // green
                str += "\033[32;1m▢ \033[0m";
            } else if (block_array[i][j]->get_color() == 3) {  // blue
                str += "\033[34;1m▢ \033[0m";
            }
        }
        str += '\n';
    }
    return str;
}
