/*
** EPITECH PROJECT, 2019
** RSD64
** File description:
** cmd.c
*/

#include "my.h"

char *Inventory(player_t *st)
{
    (void) st;
return (NULL);
}

char *Left(player_t *st)
{
    (void) st;

    st->dir = left;
    return (NULL);
}

char *Right(player_t *st)
{
    (void) st;
    st->dir = right;
    return (NULL);
}

char *Forward(player_t *st)
{
    if (st->dir == up)
        st->y++;
    else if (st->dir == back)
        st->y--;
    else if (st->dir == right)
        st->x++;
    else if (st->dir == left)
        st->x--;
    (void) st;
    return (NULL);
}
