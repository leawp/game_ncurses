//
// Created by pablo on 19.12.17.
//
#include "user_input.h"

enum Action getUserAction() {
    int ch = getch();
    switch (ch) {
        case 'w':
        case KEY_UP:
            return ACTION_UP;
        case 's':
        case KEY_DOWN:
            return ACTION_DOWN;
        case 'a':
        case KEY_LEFT:
            return ACTION_LEFT;
        case 'd':
        case KEY_RIGHT:
            return ACTION_RIGHT;
        case KEY_ENTER:
        case '\n':
            return ACTION_ENTER;
        case ' ':
            return ACTION_SPACE;
        case 'l':
            return ACTION_SHOW_STATS;
        case 'b':
            return ACTION_SPELLBOOK;
        case 'q':
            return ACTION_EXIT;
        case '`':
        case 'm':
            return ACTION_MENU;
        default:
            return ACTION_NONE;
    }
}