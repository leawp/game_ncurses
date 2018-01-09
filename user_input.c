//
// Created by pablo on 19.12.17.
//
#include "user_input.h"

enum Action getUserAction() {
    int ch = getch();
    switch (ch) {
        case KEY_UP:
            return ACTION_UP;
        case KEY_DOWN:
            return ACTION_DOWN;
        case KEY_LEFT:
            return ACTION_LEFT;
        case KEY_RIGHT:
            return ACTION_RIGHT;
        case 'l':              // shift+tab - KEY_BTAB
            return ACTION_SHOW_STATS;
        case 'q':
            return ACTION_EXIT;
        default:
            return ACTION_SKIP;
    }
}