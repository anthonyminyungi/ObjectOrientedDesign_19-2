//
// Created by 민윤기 on 2019/11/28.
//

#ifndef OOPTERMTEMP_BLOCK_H
#define OOPTERMTEMP_BLOCK_H

class block {
private:
    bool located;
    int color;
    int x, y;

    class color_block *group;

    void find_merge();

    void merge(block *b);

    bool can_merge(block *b);

public:
    block(int color);

    int get_x();

    int get_y();

    int get_color();

    bool is_located();

    color_block *get_group();

    void fix_location(bool located);

    void set_group(color_block *group);

    void set_location(int x, int y);

    void right();

    void left();

    void down();

    void down_all(bool down);

    bool can_left();

    bool can_right();

    bool can_down();

    bool can_explosion();


};


#endif //OOPTERMTEMP_BLOCK_H
