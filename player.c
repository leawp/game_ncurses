//
// Created by pablo on 09.01.18.
//

#include "player.h"
#include "types.h"

struct player Player = {
        .health = 100,
        .mana = 50,
        .shield = 0,
        .type = entity_PLAYER,
        .x = 1,
        .y = 1,
};

void init_player(){
    Player.health = 100;
    Player.mana = 50;
    Player.shield = 0;
    Player.x = 1;
    Player.y = 1;
}