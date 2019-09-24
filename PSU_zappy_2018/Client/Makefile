##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile.
##

RM	= rm -f

NAME	= ../zappy_ai

SRCS	=	./main.cpp	\
		./parser.cpp	\
		./client.cpp	\
		./IA/ai.cpp	\

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CCC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *~

re: fclean all

.PHONY:	all clean fclean re
