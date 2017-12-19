//
// Created by pablo on 19.12.17.
//

#ifndef GAME_NCURSES_TYPES_H
#define GAME_NCURSES_TYPES_H

#include <ncurses.h>

enum Action {
    UP, DOWN, LEFT, RIGHT, ATTACK, SKIP, SHOW_STATS, EXIT
};
enum Status {
    SUCCESS, FAILURE
};
struct objects {
    int value;
    const char *PLAYER;
    const char *ENEMY;
};
extern struct objects Objects; // namespaces!! :D https://stackoverflow.com/a/28535585/1983633
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
