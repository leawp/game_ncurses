//
// Created by pablo on 19.01.18.
//

#ifndef GAME_NCURSES_SPELLBOOK_H
#define GAME_NCURSES_SPELLBOOK_H

#include "types.h"

enum Spells {
    SPELL_NONE     = 0,
    SPELL_TELEPORT = 1,
    SPELL_HEAL     = 2,
    SPELL_FORTIFY  = 3,
};

enum Mode spellbook_handle_action(enum Action userAction);

#endif //GAME_NCURSES_SPELLBOOK_H
