//
// Created by pablo on 19.01.18.
//

#include "menu.h"

int  highlight = 0;
char *menu[]   = {"RESUME", "NEW GAME", "CREDITS", "EXIT"};

enum Mode menu_handle_action(enum Action userAction) {
    menu_draw();
    switch (userAction) {
        case ACTION_UP:
            highlight--;
            if (highlight == -1)
                highlight = 3;
            break;
        case ACTION_DOWN:
            highlight++;
            if (highlight == 4)
                highlight = 0;
            break;
        case ACTION_ENTER:
            switch (highlight) {
                case MENU_EXIT:
                    return MODE_EXIT;
                case MENU_RESUME:
                    return MODE_MAP;
                case MENU_NEW_GAME:
                    return MODE_RESET;
                case MENU_CREDITS:
                    wclear(stdscr);
                    return MODE_CREDITS;
                default:
                    break;
            }
        default:
            break;
    }
    return MODE_MENU;

}

void menu_draw() {
    wclear(stdscr);
    for (int i = 0; i < 4; ++i) {
        if (i == highlight) {
            wattron(stdscr, A_REVERSE);
        }
        mvwprintw(stdscr, i + 5, 10, menu[i]);
        wattroff(stdscr, A_REVERSE);
    }

}