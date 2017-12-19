//
// Created by pablo on 19.12.17.
//
#include "user_input.h"

enum Action getUserAction() {
    int ch = getch();
    switch (ch) {
        case 'w':
            return UP;
        case 's':
            return DOWN;
        case 'a':
            return LEFT;
        case 'd':
            return RIGHT;
        case KEY_BTAB:              // shift+tab
            return SHOW_STATS;
        case 'q':
            return EXIT;
        default:
            return SKIP;
    }
}