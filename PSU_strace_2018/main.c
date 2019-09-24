/*
** EPITECH PROJECT, 2019
** strace project
** File description:
** main file
*/

#include "include/my.h"

void h_help(void)
{
    printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
}

int error_handling(int ac, char *env)
{
    if (env == NULL)
        return (84);
    if (ac < 2 || ac > 4)
        return (84);
    return (0);
}

int flag_management(char **av)
{
    if (strcmp(av[1], "--help") == 0) {
        h_help();
    }
    if (strcmp(av[1], "-s") == 0)
        printf("-s match\n");
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (error_handling(ac, env[0]) == 84) {
        return (84);
    }
    flag_management(av);
    return (0);
}
