##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile.
##

export CC	= gcc
export CCC	= g++
export CFLAGS	+= -W -Wall -Wextra -Werror -g3
export CFLAGS	+= -I./include

DIR_Client	= Client
DIR_Server	= Server

NAME	+= $(DIR_Server)/zappy_server
NAME	+= $(DIR_Client)/zappy_Ai

all: $(NAME)

$(NAME):
	@(cd $(DIR_Server) && $(MAKE))
	@(cd $(DIR_Client) && $(MAKE))

clean:
	@(cd $(DIR_Server) && $(MAKE) $@)
	@(cd $(DIR_Client) && $(MAKE) $@)

fclean: clean
	@(cd $(DIR_Server) && $(MAKE) $@)
	@(cd $(DIR_Client) && $(MAKE) $@)

re: fclean all

.PHONY:	all clean fclean re
