##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for rush3
##

CC	=	gcc

CFLAGS += -fPIC -Wall -Wextra -I ./include

LDFLAGS += -shared

NAME	=	libmy_malloc.so

RM	=	rm -f

SRC	= 		malloc.c	\

OBJS	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC)  $(LDFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

.PHONY:	all clean fclean re
