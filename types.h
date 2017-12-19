//
// Created by pablo on 19.12.17.
//

#ifndef GAME_NCURSES_TYPES_H
#define GAME_NCURSES_TYPES_H
enum Action {
    UP, DOWN, LEFT, RIGHT, ATTACK, SKIP, SHOW_STATS, EXIT
};
enum Status {
    SUCCESS, FAILURE
};
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
