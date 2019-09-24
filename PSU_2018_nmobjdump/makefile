##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


CC	= gcc

RM	= rm -f

NAMENM	= my_nm

NAMEOD	= my_objdump

CFLAGS	= -W -Wextra -Werror
CFLAGS	+= -I./include

SRCSNM	= src/nm/main.c			\

SRCSOD	= src/objdump/main.c \
		  src/objdump/obj.c

OBJSNM	= $(SRCSNM:.c=.o)

OBJSOD	= $(SRCSOD:.c=.o)

all:		$(NAMENM) $(NAMEOD)

nm:		$(NAMENM)

objdump:	$(NAMEOD)

$(NAMENM):	$(OBJSNM)
		$(CC) -o $(NAMENM) $(SRCSMY) $(OBJSNM) $(CFLAGS)

$(NAMEOD):	$(OBJSOD)
		$(CC) -o $(NAMEOD) $(SRCSMY) $(OBJSOD) $(CFLAGS)

clean:
		$(RM) $(OBJSNM) $(OBJSOD)

fclean:		clean
		$(RM) $(NAMENM) $(NAMEOD)

re: fclean all

.PHONY: all clean fclean re
