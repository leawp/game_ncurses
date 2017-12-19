#include <stdio.h>
#include <ncurses.h>
#include "types.h"
#include "user_input.h"

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE); // make keys work
    curs_set(0); // hide cursor
    timeout(100);

//    int xmax;
//    int ymax;
//    getmaxyx(stdscr, ymax, xmax); // returns the size of the terminal
    enum Action useraction;       // action choice based on user input
    clear();
//    xmax++;
    while (true) {
        useraction = getUserAction();
        if (useraction == EXIT) {
            break;
        }
        if (useraction == SHOW_STATS) {
            printw("SHOW_STATS");
            Objects.value++;
        }
        printw(Objects.ENEMY);
        printw("%d", Objects.value);

        refresh();
    }
    endwin();
    return 0;
}