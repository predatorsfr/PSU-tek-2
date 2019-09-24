##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Map
##

CXX	=	g++

CXXFLAGS	+=	-Wall -Wextra -g3 -I./include

NAME	=	Map

RM	=	rm -f

SRC	=	graphe.cpp	\
		mappe.cpp

OBJS =	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CXX) -o  $(NAME) $(OBJS) -lsfml-window -lsfml-graphics -lsfml-system

clean:
	$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
