#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "map.h"

char **rand_linemate(char **map)
{
    int rands = rand() %101;

  //  srand(time(NULL));
    for (int i = 0; map[i] != NULL; i++) {
        for (int c = 0; map[i][c] != '\0'; c++) {
            rands = rand() %101;
            if (map[i][c] != 'X' && (rands >= 0 && rands <= 3)) {
                map[i][c] = 'L';
            }
        }
    }
    return (map);
}

char **rand_deraumere(char **map)
{
    int rands = rand() %101;

 //   srand(time(NULL));
    for (int i = 0; map[i] != NULL; i++) {
        for (int c = 0; map[i][c] != '\0'; c++) {
            rands = rand() %101;
            if (map[i][c] != 'X' && (rands >= 4 && rands <= 8))
                map[i][c] = 'D';
        }
    }
    return (map);
}

char **rand_sibur(char **map)
{
    int rands = rand() %101;

  //  srand(time(NULL));
    for (int i = 0; map[i] != NULL; i++) {
        for (int c = 0; map[i][c] != '\0'; c++) {
            rands = rand() %101;
            if (map[i][c] != 'X' && (rands >= 9 && rands <= 12))
                map[i][c] = 'S';
        }
    }
    return (map);
}

char **rand_mendiane(char **map)
{
    int rands = rand() %101;

//    srand(time(NULL));
    for (int i = 0; map[i] != NULL; i++) {
        for (int c = 0; map[i][c] != '\0'; c++) {
            rands = rand() %101;
            if (map[i][c] == ' ' &&  (rands >= 12 && rands <= 16))
                map[i][c] = 'M';
        }
    }
    return (map);
}

char **rand_phiras(char **map)
{
    int rands = rand() %101;

  //  srand(time(NULL));
    for (int i = 0; map[i] != NULL; i++) {
        for (int c = 0; map[i][c] != '\0'; c++) {
            rands = rand() %101;
            if (map[i][c] == ' ' &&  (rands >= 17 && rands <= 20))
                map[i][c] = 'P';
        }
    }
    return (map);
}