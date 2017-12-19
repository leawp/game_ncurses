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

    int xmax;
    int ymax;
    getmaxyx(stdscr, ymax, xmax); // returns the size of the terminal
    enum Action useraction;       // action choice based on user input

    while (true) {
        printw("%d", ymax);
        printw("%d", xmax);
        clear();
        useraction = getUserAction();
        if(useraction == EXIT){
            break;
        }

        printw("%d", ymax);
        printw("%d", xmax);
        refresh();
    }
    endwin();
    return 0;
}