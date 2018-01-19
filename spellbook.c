//
// Created by pablo on 19.01.18.
//

#include "spellbook.h"
#include "player.h"

int  spellbook_highlight = 0;
char *spellbook_menu[]   = {"TELEPORT(50mp)", "HEAL(10mp)", "FORTIFY(10mp)", "EXIT"};
WINDOW * spellbook_win;

enum Mode spellbook_handle_action(enum Action userAction) {
    spellbook_draw();
    switch (userAction) {
        case ACTION_UP:
            spellbook_highlight--;
            if (spellbook_highlight == -1)
                spellbook_highlight = 3;
            break;
        case ACTION_DOWN:
            spellbook_highlight++;
            if (spellbook_highlight == 4)
                spellbook_highlight = 0;
            break;
        case ACTION_ENTER:
            switch (spellbook_highlight){
                case 0:
                    Player.spell = SPELL_TELEPORT;
                    return  MODE_USE_SPELL;
                case 1:
                    Player.spell = SPELL_HEAL;
                    return  MODE_USE_SPELL;
                case 2:
                    Player.spell = SPELL_FORTIFY;
                    return  MODE_USE_SPELL;
            }
            return MODE_MAP;
        default:
            break;
    }
    return MODE_SPELLBOOK;

}

void spellbook_draw() {
    if(spellbook_win == NULL){
        spellbook_win = newwin(15, 40, 15, 40);
    }
    box(spellbook_win, 0, 0);
    for (int i = 0; i < 4; ++i) {
        if (i == spellbook_highlight) {
            wattron(spellbook_win, A_REVERSE);
        }
        mvwprintw(spellbook_win, i + 5, 10, spellbook_menu[i]);
        wattroff(spellbook_win, A_REVERSE);
    }
    wrefresh(spellbook_win);

}