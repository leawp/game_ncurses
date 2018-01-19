//
// Created by pablo on 09.01.18.
//

#ifndef GAME_NCURSES_PLAYER_H
#define GAME_NCURSES_PLAYER_H

struct player {
    char type;
    int  health;
    int  mana;
    int  shield;
    int  x;
    int  y;
    int  spell;

    void (*useSpell)(void);
};

extern struct player Player;
#endif //GAME_NCURSES_PLAYER_H
