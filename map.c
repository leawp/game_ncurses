//
// Created by pablo on 16.01.18.
//

#include "map.h"
#include "player.h"
#include "draw.h"


void map_load(char **map) {
    FILE *fp;
    fp     = fopen("map.txt", "r");
    char line[1000];
    char result[1000];
    int  i = 0;
    while (fgets(line, 1000, fp) != NULL) {
        asprintf(&map[i++], "%s", strtok(line, "\n"));
    }
    fclose(fp);
}

void map_handle_action(enum Action userAction, char **map) {
    if (userAction == ACTION_DOWN && map[Player.y + 1][Player.x] != '#') { //
        Player.y += 1;
        Player.health -= 2;
    } else if (userAction == ACTION_UP && map[Player.y - 1][Player.x] != '#') {
        Player.y -= 1;
    } else if (userAction == ACTION_RIGHT && map[Player.y][Player.x + 1] != '#') {
        Player.x += 1;
    } else if (userAction == ACTION_LEFT && map[Player.y][Player.x - 1] != '#') {
        Player.x -= 1;
    }
    draw_world(stdscr, map);

}