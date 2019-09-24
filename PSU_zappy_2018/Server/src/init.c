/*
** EPITECH PROJECT, 2019
** init
** File description:
** 
*/

#include "my.h"


server_t *init(char **av, int ac)
{
    int (*ptr[])(int, server_t*)= {&get_port, &get_width, &get_heigth, &get_nbteam, &get_freq, NULL};
    server_t *server = malloc(sizeof(server_t));
    int c;
    int i;

     while ((c = getopt(ac, av, "p:x:y:n:c:f:")) != -1) {
         if (c == 'n')
            get_name(av, ac, server);
	 else {
            for (i = 0 ; ptr[i] != NULL ; i++)
                if (ptr[i](c, server) == 1)
                    break;
	    if (ptr[i] == NULL) {
		    fprintf(stderr, "%s" , ERR_ARG);
		    exit(84);
	    }
	 }
     }
     return (server);
}
