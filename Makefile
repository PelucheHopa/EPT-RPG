##
## EPITECH PROJECT, 2019
## MUL_my_defender_2019
## File description:
## Makefile
##

SRC	=	src/game/*.c	\
		src/inventory/*.c	\
		src/shop/*.c	\
		src/save/*.c

UTFLAGS	=	-l criterion --coverage

NAME_TEST	=	unit_test

NAME	=	my_rpg

INCLUDE =	-I include/ -g

CFLAGS	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(INCLUDE) -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

tests_run:	all
	gcc -o $(NAME_TEST) $(UTFLAGS) $(SRCU_TEST) $(CFLAGS)
	./unit_test
	gcovr -b -e tests

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)
	rm -f *.gcno
	rm -f *.gcda
	mr_clean

re:		fclean all
## n'affiche pas les commandes
.SILENT:

## ne compare pas les fichiers
