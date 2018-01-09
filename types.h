//
// Created by pablo on 19.12.17.
//

#ifndef GAME_NCURSES_TYPES_H
#define GAME_NCURSES_TYPES_H

#include <ncurses.h>

#define entity_PLAYER "@"
#define entity_ENEMY "&"

#define item_NONE 0

enum Action {
    ACTION_UP, ACTION_DOWN, ACTION_LEFT, ACTION_RIGHT, ACTION_ATTACK, ACTION_SKIP, ACTION_SHOW_STATS, ACTION_EXIT
};
enum Status {
    SUCCESS, FAILURE
};


struct objects {
    const char *PLAYER;
    const char *ENEMY;
};
extern struct objects Objects; // namespaces!! :D https://stackoverflow.com/a/28535585/1983633

struct player {
    char *type;
    int health;
    int shield;
    int x;
    int y;
};
extern struct player Player;

//struct PointList {
//    int x;
//    int y;
//    struct PointList *next;
//};
//
//typedef struct PointList PointList;
//
//typedef struct {
//    PointList *snake;
//    PointList *foods;
//    int xmax;
//    int ymax;
//} Board;




#endif //GAME_NCURSES_TYPES_H
