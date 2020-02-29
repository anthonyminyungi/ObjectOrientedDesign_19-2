//
// Created by 김혁진 on 2019/12/11.
//

#ifndef PUYO_BLOCK_H
#define PUYO_BLOCK_H

class block {
private:
    int color;
    int x, y;

public:
    block(int x, int y, int color);

    int get_color();
    int get_x();
    int get_y();

    bool can_left();
    bool can_right();
    bool can_down();

    void move(int new_x, int new_y);
    void change(block* block);
    void make();

    void left();
    void right();
    void down();

    bool same_x(block* block);
    bool same_y(block* block);
};

#endif // PUYO_BLOCK_H
