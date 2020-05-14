##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My makefile
##

LIB_NAME =	my_config

NAME =		libmyconfig.a

SRC =		src/config.c						\
		src/load/config_loader.c				\
		src/save/config_saver.c					\

INC_DIR =	include							\

CC =		gcc

CFLAGS = 	-Wall -Wextra -Werror #-Wpedantic

CPPFLAGS =	-I $(INC_DIR)

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

.c.o:
		@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $(<:.c=.o)
		@echo -e "\033[95m[$(LIB_NAME)]\033[0m \033[92mCompiling \033[93m$<\033[0m...\033[0m"

$(NAME):	$(OBJ)
		@echo -en "\033[95m[$(LIB_NAME)]\033[0m \033[92mBuilding library...\033[0m"
		@ar rc $(NAME) $(OBJ)
		@echo -e "\033[92m Done.\033[0m"

clean:
		@rm -f $(OBJ)

fclean: 	clean
		@rm -f $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re
