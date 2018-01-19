//
// Created by pablo on 09.01.18.
//

#include "player.h"
#include "types.h"
#include "spellbook.h"


WINDOW *spellwin;

void resetcurses() {
    cbreak();
    noecho();
    keypad(stdscr, TRUE); // make keys work
    curs_set(0); // hide cursor
    timeout(50);
    clear();
    refresh();
}

void _use_spell() {
    switch (Player.spell) {
        case SPELL_TELEPORT:
            Player.mana -= 50;
            spellwin = newwin(3, 10, 20, 20);
            box(spellwin, 0, 0);

            mvwprintw(spellwin, 1, 1, "x y");
            nodelay(stdscr, FALSE);
            echo();
            mvwscanw(spellwin, 1, 1, "%d %d", &Player.x, &Player.y);
            noecho();
            nodelay(stdscr, TRUE);
            resetcurses();

            delwin(spellwin);
            if (Player.shield > 100) {
                Player.shield = 100;
            }
            break;
        case SPELL_HEAL:
            Player.mana -= 10;
            Player.health += 10;
            if (Player.health > 100) {
                Player.health = 100;
            }
            break;
        case SPELL_FORTIFY:
            Player.mana -= 10;
            Player.shield += 10;
            if (Player.shield > 100) {
                Player.shield = 100;
            }
            break;
        default:
            break;
    }
}

struct player Player = {
        .health = 100,
        .mana = 50,
        .shield = 0,
        .type = entity_PLAYER,
        .x = 1,
        .y = 1,
        .useSpell = _use_spell
};

void init_player() {
    Player.health = 100;
    Player.mana   = 50;
    Player.shield = 0;
    Player.x      = 1;
    Player.y      = 1;
}