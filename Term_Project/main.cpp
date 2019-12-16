#include <iostream>
#include "array_2d.h"
#include "fold_block.h"
#include "tree_block.h"
#include "cross_block.h"
#include <ctime>


big_block blockgen(int type, int *colors) {
    if (type == 0) {
        return fold_block(colors[0], colors[1], colors[2]);
    } else if (type == 1) {
        return tree_block(colors[0], colors[1], colors[2]);
    } else if (type == 2) {
        return cross_block(colors[0], colors[1], colors[2], colors[3], colors[4]);
    }
}


int main() {

    srand((unsigned int) time(0));
    array_2d *map = new array_2d();


    int input = 0;
    int type = rand() % 3;
    int colors[5];
    int downside = 0;

    for (int i = 0; i < 5; i++) {
        colors[i] = rand() % 4 + 1;
    }
    big_block generated = blockgen(type, colors);

    cout << "Game Start" << "\n\n";
    map->print();
    while (true) {
        cout << "input : ";
        input = getchar();
        cout << "\n\n";
        if (input == 'a')
            generated.move(0);
        else if (input == 'd')
            generated.move(1);
        else if (input == 's') {
            generated.move(2);
            downside = 1;
        } else if (input == 'x') {
            generated.down_all();
            downside = 1;
        } else if (input == 'e')
            generated.rotate();

        if (!generated.can_down() && downside) {
            map->down_all();
            map->print();

            int expc = 0;
            while (map->explosion(expc)) {
                map->down_all();
                map->print();
            }
            type = rand() % 3;

            if (!map->can_make(type))
                break;
            for (int i = 0; i < 5; i++) {
                colors[i] = rand() % 4 + 1;
            }
            generated = blockgen(type, colors);
        }
        downside = 0;
        map->print();
    }

    cout << "Game Over" << "\n" << "with score : " << map->get_score();
    return 0;
}
