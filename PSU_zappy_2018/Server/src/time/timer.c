/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "my.h"

static int check_command(char *command)
{
    if ((strcmp(command, "Forward") == 0) || (strcmp(command, "Right") == 0))
        return (7);
    if (strcmp(command, "Left") == 0)
        return (7);
    if (strcmp(command, "Look") == 0)
        return (7);
    if (strcmp(command, "Inventory") == 0)
        return (1);
    if (strcmp(command, "Broadcast text") == 0)
        return (7);
    if (strcmp(command, "Fork") == 0)
        return (42);
    if (strcmp(command, "Eject") == 0)
        return (7);
    if (strcmp(command, "Take object") == 0)
        return (7);
    if (strcmp(command, "Set object") == 0)
        return (7);
    if (strcmp(command, "Incantation") == 0)
        return (300);
    return (0);
}

void check_timer(double f, char *command)
{
    double time = check_command(command);
    double calculation = time / f;
    double time_taken;
    clock_t start;
    clock_t current;

    start = clock();
    while (time_taken <= calculation) {
        current = clock();
        time_taken = (double)(current - start) / (double)(CLOCKS_PER_SEC);
    }
}
