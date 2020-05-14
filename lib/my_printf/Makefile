##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My makefile
##

LIB_NAME =	my_printf

NAME =		libmyprintf.a

SRC =		src/my_printf.c							\
		src/utils/my_put_address.c					\
		src/utils/my_putchar.c						\
		src/utils/my_putnbr.c						\
		src/utils/my_putnbr_base.c					\
		src/utils/my_putstr.c						\

INC_DIR =	-I include

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror #-Wpedantic

CPPFLAGS =	$(INC_DIR)

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