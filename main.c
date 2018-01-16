#include <ncurses.h>
#include "types.h"
#include "user_input.h"
#include "draw.h"
#include "player.h"
#include "map.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

enum Action useraction;       // action choice based on user input
WINDOW *stats, *hp, *mana, *shield;
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
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
}

int main() {
    initCurses();
    stats = derwin(stdscr, LINES - 6, COLS / 3, 1, COLS - COLS / 3 - 2);
    int bsize = COLS - COLS / 3 - 1;
    hp = derwin(stdscr, 3, bsize / 2 - 1, LINES - 4, 1);
    mana = derwin(stdscr, 3, bsize / 2 - 1, LINES - 4, bsize / 2);
    shield = derwin(stdscr, 3, bsize / 2 - 1, LINES - 4, bsize);
    wbkgd(stats, COLOR_PAIR(1));
    wbkgd(hp, COLOR_PAIR(2));
    wbkgd(mana, COLOR_PAIR(3));

    char *map[20];
    load_map(map);

    wrefresh(mana);
    wrefresh(hp);
    stats_showed = true;

    while (true) {
        useraction = getUserAction();
        if (useraction == ACTION_EXIT) {
            break;
        } else if (useraction == ACTION_SHOW_STATS) {
            if (stats_showed) {
                wclear(stats);
                stats_showed = false;
            } else {
                stats_showed = true;
            }

        } else if (useraction == ACTION_DOWN && map[Player.y + 1][Player.x] != '#') {
            Player.y += 1;
            Player.health -= 2;
        } else if (useraction == ACTION_UP && map[Player.y - 1][Player.x] != '#') {
            Player.y -= 1;
        } else if (useraction == ACTION_RIGHT && map[Player.y][Player.x + 1] != '#') {
            Player.x += 1;
        } else if (useraction == ACTION_LEFT && map[Player.y][Player.x - 1] != '#') {
            Player.x -= 1;
        }


        draw_world(stdscr, map);

        if (stats_showed)
            draw_stats(stats);
        wrefresh(stats);

        wclear(hp);
        box(hp, 0, 0);
        for (int i = 1; i < Player.health / 2 + 1; ++i) {
            mvwaddch(hp, 1, i, ACS_CKBOARD);
        }
        wclear(mana);
        box(mana, 0, 0);
        for (int i = 1; i < Player.mana / 2 + 1; ++i) {
            mvwaddch(mana, 1, i, ACS_CKBOARD);
        }
        wclear(shield);
        box(shield, 0, 0);
        for (int i = 1; i < Player.shield / 2 + 1; ++i) {
            mvwaddch(shield, 1, i, ACS_CKBOARD);
        }

        wrefresh(stdscr);
        wrefresh(hp);
        wrefresh(mana);


    }
    endwin();
    getch();
    return 0;
}

#pragma clang diagnostic pop