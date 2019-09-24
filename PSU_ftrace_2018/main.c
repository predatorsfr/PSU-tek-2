/*
** EPITECH PROJECT, 2019
** strace project
** File description:
** main file
*/

#include "include/my.h"

void h_help(void)
{
    printf("USAGE: ./ftrace <command>\n");
}

int error_handling(int ac, char *env)
{
    if (env == NULL)
        return (84);
    if (ac < 2 || ac > 3)
        return (84);
    return (0);
}

int flag_management(char **av)
{
    if (strcmp(av[1], "--help") == 0) {
        h_help();
        return (1);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (error_handling(ac, env[0]) == 84) {
        return (84);
    }
    if (flag_management(av) == 1)
        return (0);
    //toto_function();
    //tutu_function();
    return (0);
}
