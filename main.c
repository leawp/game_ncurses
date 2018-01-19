#include <ncurses.h>
#include "types.h"
#include "user_input.h"
#include "draw.h"
#include "player.h"
#include "map.h"
#include "menu.h"
#include "stats.h"
#include "credits.h"
#include "spellbook.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

enum Action userAction;       // action choice based on user input
enum Mode   currentMode = MODE_MAP;

WINDOW *stats, *hp, *mana, *shield;
bool stats_showed       = false;

void initCurses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE); // make keys work
    curs_set(0); // hide cursor
    timeout(50);
    clear();
    refresh();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
}

void initWindows() {
    stats     = derwin(stdscr, LINES - 6, COLS / 3, 1, COLS - COLS / 3 - 2);
    int bsize = COLS - COLS / 3 - 1;

    hp     = derwin(stdscr, 3, bsize / 2 - 1, LINES - 4, 1);
    mana   = derwin(stdscr, 3, bsize / 2 - 1, LINES - 4, bsize / 2);
    shield = derwin(stdscr, 3, bsize / 2 - 1, LINES - 4, bsize);

    //initialize colors for windows
    wbkgd(stats, COLOR_PAIR(1));
    wbkgd(hp, COLOR_PAIR(2));
    wbkgd(mana, COLOR_PAIR(3));

}

int main() {
    initCurses();
    initWindows();

    char *map[20];
    map_load(map);

    stats_showed = true;

    while (true) {
        userAction = getUserAction();

        switch (currentMode) {
            case MODE_MAP:
                map_handle_action(userAction, map);
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
                break;
            case MODE_MENU:
                currentMode = menu_handle_action(userAction);
                break;
            case MODE_SPELLBOOK:
                currentMode = spellbook_handle_action(userAction);
                break;
            case MODE_USE_SPELL:
                Player.useSpell();
                currentMode = MODE_MAP;
                break;
            case MODE_STATS:
                currentMode = stats_handle_action(userAction);
                break;
            case MODE_CREDITS:
                currentMode = credits_handle_action(userAction);
                break;
            case MODE_RESET:
                break;
            default:
                break;
        }
        if (currentMode == MODE_EXIT) {
            break;
        }
        if (userAction == ACTION_SHOW_STATS) {
            if (stats_showed) {
                wclear(stats);
                stats_showed = false;
            } else {
                stats_showed = true;
            }
        } else if (userAction == ACTION_MENU) {
            currentMode = MODE_MENU;
        } else if (userAction == ACTION_SPELLBOOK) {
            currentMode = MODE_SPELLBOOK;
        }


        wrefresh(stdscr);
    }
    endwin();
    getch();
    resetterm();
    return 0;
}

#pragma clang diagnostic pop