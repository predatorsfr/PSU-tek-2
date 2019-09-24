/*
** EPITECH PROJECT, 2019
** RSD64
** File description:
** run_s.c
*/

#define MAXMSG 2000
#include "my.h"

player_t *find_player(server_t *serv, uint16_t port)
{
    team_t *team = serv->lst_team;
    player_t *player;

    while (team != NULL) {
        while (player != NULL) {
            if (player->port == port)
                return (player);
            player = player->next;
        }
        team = team->next;
    }
    return (NULL);
}

char *parse_cmd(uint16_t port, server_t *serv, char *buffer)
{
    player_t *player = find_player(serv, port);
    char *(*ptr[])(player_t *st)= {&Inventory, &Left, &Right, &Forward, &Broadcast_text, &Connect_nbr, &Fork, &Suicide, &Take_object, &Incantation, &Set_object, NULL};
    char *ptr2[12] = {"Inventory", "Left", "Right", "Forward", "Broadcast_text", "Connect_nbr", "Fork", "Suicide", "Take_object", "Incantation", "Set_object", NULL};

    for (int i = 0 ; ptr[i] != NULL ; i++)
            if (strncmp(ptr2[i], buffer, strlen(ptr2[i]))) {
                return (ptr[i](player));
            }
    return(KO);
}

int read_from_client (int filedes, struct sockaddr_in clientname, server_t *st)
{
  char buffer[MAXMSG];
  int nbytes;
  char *ret;

  nbytes = read (filedes, buffer, MAXMSG);
  if (nbytes < 0) {
      perror ("read");
      exit (EXIT_FAILURE);
    }
  else if (nbytes == 0)
    return -1;
  else {
    if (create_player(st,buffer, clientname.sin_port, filedes) != 84) {
        ret = parse_cmd(clientname.sin_port, st, buffer);
        write(filedes, ret, strlen(ret));
    }
    return 0;
    }
}

bool client(server_t *st)
{
    struct sockaddr_in clientname;
    socklen_t size = sizeof(clientname);
    int i;

    FD_ZERO(&st->act_set);
    FD_SET (st->fd, &st->act_set);
    while (1) {
        st->read_set = st->act_set;
        if (select (FD_SETSIZE, &st->read_set, NULL, NULL, NULL) < 0) {
          perror ("select");
          exit (EXIT_FAILURE);
        }
        for (i = 0; i < FD_SETSIZE; ++i)
            if (FD_ISSET (i, &st->read_set)) {
                if (i == st->fd) {
                    int new;
                    size = sizeof (clientname);
                    new = accept (st->fd, (struct sockaddr *) &clientname, &size);
                    if (new < 0) {
                        perror ("accept");
                        exit (EXIT_FAILURE);
                    }
                    write(i, WELCOME, strlen(WELCOME));
                    //ntohs (clientname.sin_port));
                    FD_SET (new, &st->act_set);
                } else {
                    if (read_from_client(i, clientname, st) < 0) {
                    FD_CLR (i, &st->act_set);
                  }
              }
          }
    }
    if (close(st->client_fd) == -1)
        return (false);
}
