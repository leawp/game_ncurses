#include <stdio.h>
#include <ncurses.h>
#include "types.h"
#include "user_input.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"


enum Action useraction;       // action choice based on user input
WINDOW *world, *stats;

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE); // make keys work
    curs_set(0); // hide cursor
    timeout(100);
    clear();
    world = newwin(LINES, COLS, 0, 0);
    stats = newwin(0, 0, LINES, COLS - COLS / 3);

    bool stats_showed = false;
    int x = 1, y = 1;
    while (true) {
        useraction = getUserAction();
        if (useraction == ACTION_EXIT) {
            break;
        } else if (useraction == ACTION_SHOW_STATS) {
            if (stats_showed) {
                wresize(world, LINES, COLS);
                wresize(stats, 0, 0);
                stats_showed = false;
            } else {
                wresize(world, LINES, COLS - COLS / 3);
                wresize(stats, LINES, COLS / 3);
                stats_showed = true;
            }

        } else if (useraction == ACTION_DOWN) {
            y += 1;
        } else if (useraction == ACTION_UP) {
            y -= 1;
        } else if (useraction == ACTION_RIGHT) {
            x += 1;
        } else if (useraction == ACTION_LEFT) {
            x -= 1;
        }

//        printw(Objects.ENEMY);
//        printw("%d", Objects.value);

        wclear(world);
        box(world, 0, 0);
        mvwaddstr(world, y, x, "XDDD");

        wclear(stats);
        box(stats, 0, 0);
        wrefresh(world);
        wrefresh(stats);
    }
    endwin();
    return 0;
}

#pragma clang diagnostic pop