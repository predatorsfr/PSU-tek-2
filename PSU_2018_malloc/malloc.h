/*
** EPITECH PROJECT, 2019
** malloc.h
** File description:
** kevin
*/

#ifndef _MALLOC_H__
#define _MALLOC_H__


typedef struct s_memory *memory;

struct s_memory {
    memory next;
    size_t size;
    int free;
    void *data;
};

#endif
