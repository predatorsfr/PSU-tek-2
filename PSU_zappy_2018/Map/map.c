/*
** EPITECH PROJECT, 2019
** map
** File description:
** in c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "map.h"

char **create_map(int _x, int _y)
{
    char **map = malloc(sizeof(char*) * _x + 1);

    map[_x] = NULL;
    for (int i = 0; i < _x; i++) {
        map[i] = malloc(sizeof(map) * _y + 1);
        map[i][_y] = '\0';
    }
    for (int i = 0; i < _y; i++)
        map[0][i] = 'X';
    for (int i = 1; i < _x; i++) {
        map[i][0] = 'X';
        for (int c = 1; c < _y; c++)
            map[i][c]= ' ';
        map[i][_y - 1] = 'X';
    }
    for (int i = 0; i < _y; i++)
            map[_x - 1][i] = 'X';
    return (map);
}

char **rand_thystame(char **map)
{
    int rands = rand()% 101;

    for (int i = 0; map[i] != NULL; i++) {
        for (int c = 0; map[i][c] != '\0'; c++) {
            rands = rand() %101;
            if (map[i][c] == ' ' &&  (rands >= 21 && rands <= 24))
                map[i][c] = 'T';
        }
    }
    return (map);
}

char **rand_food(char **map)
{
    int rands = rand()% 101;

    for (int i = 0; map[i] != NULL; i++) {
        for (int c = 0; map[i][c] != '\0'; c++) {
            rands = rand()%101;
            if (map[i][c] == ' ' && (rands >=25 && rands <= 29))
                map[i][c] = 'F';
        }
    }
    return (map);
}

char **gen_map(int x, int y)
{
    char **map;

    map = create_map(x, y);
    map = rand_linemate(map);
    map = rand_deraumere(map);
    map = rand_sibur(map);
    map = rand_mendiane(map);
    map = rand_phiras(map);
    map = rand_thystame(map);
    map = rand_food(map);

    for (int i = 0; map[i] != NULL; i++)
        puts(map[i]);
}

int main (int ac, char **av)
{
    gen_map(atoi(av[1]), atoi(av[2]));
}
