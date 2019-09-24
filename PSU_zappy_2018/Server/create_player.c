/*
** EPITECH PROJECT, 2019
** create_player
** File description:
** 
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y) {
	char t = *x; *x = *y; *y = t;
}

char* reverse(char *buffer, int i, int j)
{
	while (i < j)
		swap(&buffer[i++], &buffer[j--]);

	return buffer;
}
 
char* itoa(int value, char* buffer, int base)
{
	if (base < 2 || base > 32)
		return buffer;

	int n = abs(value);

	int i = 0;
	while (n)
	{
		int r = n % base;

		if (r >= 10) 
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / base;
	}
	if (i == 0)
		buffer[i++] = '0';
	if (value < 0 && base == 10)
		buffer[i++] = '-';
	buffer[i] = '\0'; // null terminate string
	return reverse(buffer, 0, i - 1);
}

void send_begin(int i, int nb, server_t *serv)
{
    char buffer[300];
    char add[300];
    int last = nb - serv->clientNb;
    int length = strlen(buffer);

    itoa(last, buffer, 10);
    buffer[length] = '\n';
    write(i, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    itoa(serv->height, buffer, 10);
    length = strlen(buffer);
    buffer[length] = ' ';
    itoa(serv->width, add, 10);
    strcat(buffer, add);
    length = strlen(buffer);
    buffer[length] = '\n';
    write(i, buffer, strlen(buffer));
}

int create_player(server_t *serv, char *team, uint16_t port, int i)
{
    team_t *first = serv->lst_team;
    player_t* play;

    while (first != NULL) {
        if (strncmp(team, first->name, strlen(first->name)) == 0) {
            if (first->nbPlayer != serv->clientNb) {
                play = first->lst_player;
                if (play->port == 0) {
                    play->port = port;
                    first->nbPlayer++;;
                    send_begin(i, first->nbPlayer, serv);
                    return (0);
                }
            }
            write(i, KO, strlen(KO));
            return (0);
        }
    }
    return (84);
}
