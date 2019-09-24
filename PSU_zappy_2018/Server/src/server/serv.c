/*
** EPITECH PROJECT, 2019
** RSD64
** File description:
** serv.c
*/

#include "my.h"

bool serv(server_t *st)
{
    struct protoent *p = getprotobyname("TCP");
    struct sockaddr_in src_in;

    
    if (!p)
	return (false);
    src_in.sin_family = AF_INET;
    src_in.sin_port = htons(st->port);
    src_in.sin_addr.s_addr = INADDR_ANY;
    if ((st->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        return (false);
    }
    if (bind(st->fd, (const struct sockaddr *)&src_in, sizeof(src_in)) == -1
        || listen(st->fd, 42) == -1) {
        if (close(st->client_fd) == -1)
            return (false);
        return (false);
    }
    return (true);
}
