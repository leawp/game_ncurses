//
// Created by pablo on 19.12.17.
//

#ifndef GAME_NCURSES_TYPES_H
#define GAME_NCURSES_TYPES_H

#include <ncurses.h>

#define entity_PLAYER '@'
#define entity_ENEMY '&'

#define item_NONE 0

enum Action {
    ACTION_UP, ACTION_DOWN, ACTION_LEFT, ACTION_RIGHT, ACTION_ENTER, ACTION_SPACE, ACTION_SHOW_STATS, ACTION_MENU, ACTION_EXIT, ACTION_NONE, ACTION_SPELLBOOK,
};

// game mode ( state machine )
enum Mode {
    MODE_MENU, MODE_MAP, MODE_STATS, MODE_EXIT, MODE_RESET, MODE_CREDITS, MODE_SPELLBOOK, MODE_USE_SPELL,
};

struct objects {
    const char PLAYER;
    const char ENEMY;
};
extern struct objects  Objects; // namespaces!! :D https://stackoverflow.com/a/28535585/1983633


struct viewport {
    int size_x;
    int size_y;
    int offset_x;
    int offset_y;
};
extern struct viewport Viewport;



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
