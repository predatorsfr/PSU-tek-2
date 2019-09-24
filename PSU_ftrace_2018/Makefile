##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

INC	=	-I./include

CC	=	gcc -g

NAME	=	ftrace

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(INC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f *~

re:		fclean all

.PHONY : 	all clean fclean re
