/*
** EPITECH PROJECT, 2019
** fct_getopt
** File description:
**
*/

#include "my.h"


int get_port(int c, server_t *serv)
{
    int temp;

    if (c == 'p') {
        if ((temp = atoi(optarg)) > 0) {
            serv->port = temp;
            return (1);
        }
        fprintf(stderr, "%s" , ERR_ARG);
        exit(84);
    }
    return (0);
}

int get_width(int c, server_t *serv)
{
    int temp;

    if (c == 'x') {
        if ((temp = atoi(optarg)) > 0) {
            serv->width = temp;
            return (1);
        }
        fprintf(stderr, "%s" , ERR_ARG);
        exit(84);
    }
    return (0);
}

int get_heigth(int c, server_t *serv)
{
    int temp;

    if (c == 'y') {
       if ((temp = atoi(optarg)) > 0) {
            serv->height = temp;
            return (1);
       }
        fprintf(stderr, "%s" , ERR_ARG);
        exit(84);
    }
    return (0);
}

int get_nbteam(int c, server_t *serv)
{
    int temp;

    if (c == 'c') {
        if ((temp = atoi(optarg)) > 0) {
            serv->clientNb = temp;
            return (1);
        }
        fprintf(stderr, "%s" , ERR_ARG);
        exit(84);
    }
    return (0);
}

int get_freq(int c, server_t *serv)
{
    int temp;

    if (c == 'f') {
        if ((temp = atoi(optarg)) > 0) {
            serv->freq = temp;
            return (1);
        }
        fprintf(stderr, "%s" , ERR_ARG);
        exit(84);
    }
    return (0);
}
