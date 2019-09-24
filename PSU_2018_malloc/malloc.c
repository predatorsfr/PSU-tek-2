/*
** EPITECH PROJECT, 2019
** malloc.c
** File description:
** kevin
*/

#include <unistd.h>
#include <stdio.h>
#include "malloc.h"

void *base = NULL;
memory begin = NULL;

memory add_on_top(memory last, size_t size)
{
    memory new;

    new = sbrk(0);
    if (sbrk(sizeof(struct s_memory)) == (void *) -1)
        return NULL;
    new->size = size;
    new->free = 0;
    new->data = sbrk(size);
    if (last != NULL)
        last->next = new;
    new->next = NULL;
    return new;
}

memory check_block(memory begin, size_t size)
{
    memory tmp = begin;

    while (tmp != NULL) {
        if (tmp->size >= size && tmp->free == 1) {
            tmp->free = 0;
            return (tmp);
        }
        tmp = tmp->next;
    }
    return NULL;
}

void *malloc(size_t size)
{
    memory new;
    memory last;

    if (base != NULL) {
        last = base;
        new = check_block(begin, size);
        if (new == NULL) {
            new = add_on_top(last, size);
            if (new == NULL)
                return NULL;
        }
        base = new;
    } else {
        new = add_on_top(NULL, size);
        if (new == NULL)
            return NULL;
        base = new;
        begin = new;
    }
    return new->data;
}

void free(void *ptr)
{
    memory tmp = ptr -= sizeof(struct s_memory);
    tmp->free = 1;
}
