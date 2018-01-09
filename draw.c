//
// Created by pablo on 09.01.18.
//

#include <malloc.h>
#include "draw.h"
#include "types.h"
#include "player.h"


void draw_world(WINDOW *win) {
    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, Player.y, Player.x, Player.type);
}

void draw_stats(WINDOW *win) {
    wclear(win);
    char *hp;
    asprintf(&hp, "Health: %d", Player.health);
    mvwprintw(win, 5, 5, hp);
    free(hp);
}
