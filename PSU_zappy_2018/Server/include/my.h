/*
*** EPITECH PROJECT, 2019
** RSD64
** File description:
** my.h
*/
#ifndef HEADER_H_
#define HEADER_H_
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <ctype.h>
#include <getopt.h>
#include <sys/select.h>


#define HELP "USAGE: ./zappy_server -p port -x width\n\
     -y height -n name1 name2 ... -c clientsNb -f freq\n\
    port\t  is the port number\n\
    width\t  is the width of the world\n\
    height\t  is the height of the world\n\
    nameX\t  is the name of the team X\n\
    clientsNb is the number of authorized clients per team\n\
    freq\t  is the reciprocal of time unit for execution of actions\n"
#define WELCOME "WELCOME\n"
#define ERR_ARG "Error argument\n"
#define KO "ko\n"

typedef struct player_s {
    uint16_t port;
    bool alive;
    int x;
    int y;
    int level;
    enum direction { up, right, back, left }dir;
    struct player_s *next;
}player_t;

typedef struct team_s {
        char *name;
                int nbPlayer;
        player_t *lst_player;
        struct team_s *next;
}team_t;

typedef struct server_s {
            fd_set act_set;
                fd_set read_set;
        int port;
        int fd;
        int client_fd;
        char *client_ip;
        char *line;
        char **cmd;
        char **map;
        int width;
        int height;
        int clientNb;
        int freq;
        team_t *lst_team;
} server_t;


bool serv(server_t *stct);
bool client(server_t *stct);
void run_cmd(server_t *stct);
char **my_str_to_wordtab(char *str, char separator);
void init_lst_player(server_t *serv);
int create_player(server_t *serv, char *team, uint16_t port, int i);

int get_port(int c, server_t *serv);
int get_width(int c, server_t *serv);
int get_heigth(int c, server_t *serv);
int get_nbteam(int c, server_t *serv);
int get_freq(int c, server_t *serv);

char* Inventory(player_t *st);
char* Left(player_t *st);
char* Right(player_t *st);
char* Take_object(player_t *st);
char* Broadcast_text(player_t *st);
char* Connect_nbr(player_t *st);
char* Fork(player_t *st);
char* Suicide(player_t *st);
char* Forward(player_t *st);
char* Incantation(player_t *st);
char* Set_object(player_t *st);


void get_name(char **av, int ac, server_t *serv);
server_t *init(char **av, int ac);
team_t *init_team(char **av, int ac);
player_t *init_player(int nb, int max);

void check_timer(double f, char *command);

//static  int (*ptr[])(int, server_t*)= {&get_port, &get_width, &get_heigth, &get_nbteam, &get_freq, NULL};

#endif /* !HEADER_H_ */
