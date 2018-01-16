//
// Created by pablo on 16.01.18.
//

#include <string.h>
#include "map.h"


void load_map(char **map) {
    FILE *fp;
    fp = fopen("map.txt", "r");
    char line[1000];
    char result[1000];
    int i = 0;
    while (fgets(line, 1000, fp) != NULL) {
        asprintf(&map[i++], "%s", strtok(line, "\n"));
    }
    fclose(fp);
}