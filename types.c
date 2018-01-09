//
// Created by pablo on 20.12.17.
//
#include "types.h"

struct objects Objects = {
        .PLAYER=entity_PLAYER,
        .ENEMY=entity_ENEMY,
};



struct player Player = {
        .health = 100,
        .shield = 50,
        .type = entity_PLAYER,
        .x = 1,
        .y = 1
};

