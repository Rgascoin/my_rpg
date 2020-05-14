##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My makefile
##

LIB_NAME =	my_cgraph

NAME =		libmycgraph.a

SRC =		src/animation/animation.c					\
		src/audio/audio.c						\
		src/collision/collision.c					\
		src/render/button/button.c					\
		src/render/button/button_event.c				\
		src/render/button/button_utils.c				\
		src/render/scene/scene.c					\
		src/render/scene/scene_utils.c					\
		src/render/text/text.c						\
		src/render/text/text_utils.c					\
		src/render/texture/texture.c					\
		src/render/texture/texture_utils.c				\
		src/render/window/window.c					\
		src/render/window/window_utils.c				\

INC_DIR =	include								\

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

.PHONY:		all clean fclean re
