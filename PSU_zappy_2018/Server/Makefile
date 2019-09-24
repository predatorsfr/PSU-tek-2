##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile.
##

RM	= rm -f

NAME	= ../zappy_server

SRCS	=	./main_Server.c	\
		./src/str_to_wordtab.c	\
		./src/server/client.c	\
		./src/server/serv.c	\
		./src/time/timer.c	\
		./src/init.c	\
		./src/fct_getopt.c	\
		./src/get_name.c	\
		./src/command/cmd.c	\
		./src/command/cmd1.c	\
		./src/command/cmd2.c	\
		./src/command/look.c	\
		./create_player.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *~

re: fclean all

.PHONY:	all clean fclean re
