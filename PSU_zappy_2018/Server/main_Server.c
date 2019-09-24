/*
** EPITECH PROJECT, 2019
** RSD64
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    server_t *server;

    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        fprintf(stderr, "%s", HELP);
        return (0);
    } else {
        if (ac >= 13) {
            server = init(av, ac);
            init_lst_player(server);
        if (!serv(server))
            return (84);
        else if (!client(server))
            return (84);
        if (close(server->fd) == -1)
            return (84);
        }
    }
    return (84);
}
