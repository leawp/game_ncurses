//
// Created by pablo on 09.01.18.
//

#include "draw.h"
#include "types.h"
#include "player.h"


void draw_stats(WINDOW *win) {

}

void draw_world(WINDOW *win) {
    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, Player.y, Player.x, Player.type);
}
