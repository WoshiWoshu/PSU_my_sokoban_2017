##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile the libmy
##

CC = gcc

CFLAGS = -lncurses

RM = rm -f

SRC =	my_sokoban.c \
	main.c \
	to_char.c

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
