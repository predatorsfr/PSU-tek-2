/*
** EPITECH PROJECT, 2019
** get_name
** File description:
** 
*/

#include "my.h"


player_t *init_player(int nb, int max)
{
    player_t *player = malloc(sizeof(player_t));

    player->port = 0;
    nb++;
    if (nb == max) {
        player->next = NULL;
        return (player);
    } else
        player->next = init_player(nb, max);
    return (player);
}

team_t *init_team(char **av, int ac)
{
    team_t *team = malloc(sizeof(team_t));

    team->name = malloc(sizeof(team_t));
    strcpy(team->name, av[optind]);

    optind++;
    if (optind >=  ac || *av[optind] == '-') {
        team->next = NULL;
        return (team);
    } else
        team->next = init_team(av, ac);
    return (team);
}

void init_lst_player(server_t *serv)
{
    team_t *team = serv->lst_team;

    while (team != NULL) {
        team->lst_player = init_player(0, serv->clientNb);
        team = team->next;
    }
}

void get_name(char **av, int ac, server_t *serv)
{
    optind--;
    serv->lst_team = init_team(av, ac);    
}
