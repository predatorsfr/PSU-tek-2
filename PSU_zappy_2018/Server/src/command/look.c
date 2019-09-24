/*
** EPITECH PROJECT, 2019
** Zappy
** File description:
** This file contains the function about the server command LOOK
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

char *final_look(char *view, char resource)
{
    int size = strlen(view);

    if (resource == 'F') {
        view = realloc(view, size + 7);
        view = strcat(view, " food,");
    }
    if (resource == 'K') {
        view = realloc(view, size + 9);
        view = strcat(view, " player,");
    }
    return (view);
}

char *continue_look(char *view, char resource)
{
    int size = strlen(view);

    if (resource == 'S') {
        view = realloc(view, size + 8);
        view = strcat(view, " sibur,");
    }
    if (resource == 'M') {
        view = realloc(view, size + 11);
        view = strcat(view, " mendiane,");
    }
    if (resource == 'P') {
        view = realloc(view, size + 9);
        view = strcat(view, " phiras,");
    }
    if (resource == 'T') {
        view = realloc(view, size + 11);
        view = strcat(view, " thystame,");
    }
    view = final_look(view, resource);
    return (view);
}

char *create_look(char *view, char resource)
{
    int size = strlen(view);

    if (resource != 'L' && resource != 'D' && resource != 'S'
       && resource != 'M' && resource != 'P' && resource != 'T'
       && resource != 'F' && resource != 'K') {
        printf("resource = %c\n", resource);
        view = realloc(view, size + 2);
        view[size] = ',';
        view[size + 1] = '\0';
    }
    if (resource == 'L') {
        view = realloc(view, size + 12);
        view = strcat(view, " linemate,");
    }
    if (resource == 'D') {
        view = realloc(view, size + 13);
        view = strcat(view, " deraumere,");
    }
    view = continue_look(view, resource);
    return (view);
}

char *put_bracket(char *view)
{
    int size = strlen(view);

    view = realloc(view, size + 2);
    view[size - 1] = ']';
    view[size] = '\0';
    return (view);
}

char *look(player_t *player, char **map)
{
    int i = 0;
    int y = player->y - 1;
    int x = player->x + 1;
    int total = 3;
    char *view = strdup("[player,");

    while (i < player->level) {
        for (int c = 0; c < total; c++) {
            view = create_look(view, map[x][y]);
            y++;
        }
        x++;
        y = player->y - 1;
        total = total + 2;
        i++;
    }
    view = put_bracket(view);
    return (view);
}
