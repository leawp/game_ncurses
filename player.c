//
// Created by pablo on 09.01.18.
//

#include "player.h"
#include "types.h"
#include "spellbook.h"

void _use_spell() {
    switch (Player.spell) {
        case SPELL_TELEPORT:
            break;
        case SPELL_HEAL:
            break;
        case SPELL_FORTIFY:
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