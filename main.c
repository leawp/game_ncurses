#include <ncurses.h>
#include "types.h"
#include "user_input.h"
#include "draw.h"
#include "player.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"


enum Action useraction;       // action choice based on user input
WINDOW *world, *stats;

void initCurses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE); // make keys work
    curs_set(0); // hide cursor
    timeout(100);
    clear();
}

int main() {
    initCurses();
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
            Player.y += 1;
        } else if (useraction == ACTION_UP) {
            Player.y -= 1;
        } else if (useraction == ACTION_RIGHT) {
            Player.x += 1;
        } else if (useraction == ACTION_LEFT) {
            Player.x -= 1;
        }

        draw_world(world);



        wclear(stats);
        box(stats, 0, 0);
        wrefresh(world);
        wrefresh(stats);
    }
    endwin();
    return 0;
}

#pragma clang diagnostic pop