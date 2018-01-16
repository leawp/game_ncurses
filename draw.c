//
// Created by pablo on 09.01.18.
//

#include <malloc.h>
#include "draw.h"
#include "types.h"
#include "player.h"


void draw_world(WINDOW *win, char **map) {
    wclear(win);
    box(win, 0, 0);
    char *tempstr;
    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 50; ++x) {
            if (Player.x == x && Player.y == y) {
                if (map[y][x] == 'S') {
                    Player.shield += 50;
                    map[y][x] = ' ';
                } else if (map[y][x] == 'H') {
                    Player.health = 100;
                    map[y][x] = ' ';
                }
            } else if (map[y][x] == '@') {
                Player.x = x;
                Player.y = y;
                map[y][x] = ' ';
            } else {
                asprintf(&tempstr, "%c", map[y][x]);
                mvwprintw(win, y + 2, x + 5, tempstr);
                free(tempstr);
            }
        }
    }
    mvwprintw(win, Player.y + 2, Player.x + 5, Player.type);
}

void draw_stats(WINDOW *win) {
    wclear(win);
    char *hp;
    asprintf(&hp, "Health: %d", Player.health);
    mvwprintw(win, 2, 5, hp);
    free(hp);

    asprintf(&hp, "Mana: %d", Player.mana);
    mvwprintw(win, 3, 5, hp);
    free(hp);

    asprintf(&hp, "Shield: %d", Player.shield);
    mvwprintw(win, 4, 5, hp);
    free(hp);
}
