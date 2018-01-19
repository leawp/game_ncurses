//
// Created by pablo on 19.01.18.
//

#include <zconf.h>
#include "credits.h"


int  currentOffset = 50;
char *credits[]    = {"PROJECT:", "GAME NCURSES", "", "AUTHORS:", "Pawel Handrysik", "Dominik Szyja", "Dawid Szyja", "", "REPOSITORY", "https://github.com/pawelhandrysik/game_ncurses"};

enum Mode credits_handle_action(enum Action userAction) {
    wclear(stdscr);
    currentOffset--;
    if (currentOffset == -10) {
        currentOffset = 50;
        return MODE_MENU;
    }
    for (int i = 0; i < 10; ++i) {
        mvwprintw(stdscr, i+currentOffset, 30, credits[i]);
    }
    wrefresh(stdscr);
    usleep(250000);
    return MODE_CREDITS;
}