#include <ncurses.h>
#include "types.h"
#include "user_input.h"
#include "draw.h"
#include "player.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

enum Action useraction;       // action choice based on user input
WINDOW *world, *stats;
bool stats_showed = false;

void initCurses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE); // make keys work
    curs_set(0); // hide cursor
    timeout(100);
    clear();
    refresh();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
}

int main() {
    initCurses();
    world = stdscr;
    stats = derwin(stdscr, LINES - 2, COLS / 3, 1, COLS - COLS / 3 - 2);
    wbkgd(stats, COLOR_PAIR(1));
    stats_showed = true;

    int x = 1, y = 1;
    while (true) {
        useraction = getUserAction();
        if (useraction == ACTION_EXIT) {
            break;
        } else if (useraction == ACTION_SHOW_STATS) {
            if (stats_showed) {
                delwin(stats);
                stats_showed = false;
            } else {
                delwin(stats);
                stats = derwin(stdscr, LINES - 2, COLS / 3, 1, COLS - COLS / 3 - 2);
                wbkgd(stats, COLOR_PAIR(1));
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

        draw_world(stdscr);
        if (stats_showed)
            draw_stats(stats);


        wrefresh(stdscr);
        if(stats != NULL){
            wrefresh(stats);
        }
    }
    endwin();
    getch();
    return 0;
}

#pragma clang diagnostic pop