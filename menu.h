//
// Created by pablo on 19.01.18.
//

#ifndef GAME_NCURSES_MENU_H
#define GAME_NCURSES_MENU_H


#include "types.h"

enum MenuChoice {
    MENU_RESUME   = 0,
    MENU_NEW_GAME = 1,
    MENU_CREDITS  = 2,
    MENU_EXIT     = 3,
};

enum Mode menu_handle_action(enum Action userAction);

void menu_draw();

#endif //GAME_NCURSES_MENU_H
