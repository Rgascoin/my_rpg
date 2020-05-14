##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My makefile
##

NAME =		my_rpg

SRC		=	src/core/main.c													\
			src/core/my_rpg.c												\
			src/destroy/destroy_assets.c									\
			src/env/env_error.c												\
			src/game/animation/arena/arena.c								\
			src/game/animation/background/background.c						\
			src/game/animation/fight/animator.c								\
			src/game/animation/fight/fighters.c								\
			src/game/animation/fight/player.c								\
			src/game/animation/hospital/npc.c								\
			src/game/animation/player/animator.c							\
			src/game/animation/player/hide.c								\
			src/game/animation/player/moves.c								\
			src/game/events/button/event_button.c							\
			src/game/events/keyboard/event_keyboard.c						\
			src/game/events/window/event_window.c							\
			src/game/events/event_handler.c									\
			src/game/fight/end.c											\
            src/game/fight/end_win_check.c                                  \
			src/game/fight/fight.c											\
			src/game/fight/loader.c											\
			src/game/fight/start.c											\
			src/game/gamestate/gamestate.c									\
			src/game/handler/camera.c										\
			src/game/handler/game_handler.c									\
			src/game/handler/game_loop.c									\
			src/game/hud/fight.c											\
			src/game/hud/hud.c												\
			src/game/hud/move.c												\
			src/game/inventory/death.c										\
			src/game/inventory/inventory.c									\
			src/game/inventory/life.c										\
			src/game/inventory/print.c										\
			src/game/menu/callback/fight/attack.c							\
			src/game/menu/callback/fight/fight.c							\
			src/game/menu/callback/fight/print.c							\
			src/game/menu/callback/callback_global.c						\
			src/game/menu/callback/callback_level_up.c						\
			src/game/menu/callback/callback_sound.c							\
			src/game/menu/callback/callback_main_menu.c						\
			src/game/menu/callback/callback_option_menu.c					\
			src/game/menu/level_up.c										\
			src/game/player/collision.c										\
			src/game/player/heal.c											\
			src/game/player/level.c											\
			src/game/player/movements.c										\
			src/game/player/walk.c											\
			src/game/player/visibility.c									\
			src/game/quest/quest_interaction.c								\
			src/game/quest/quest_status.c									\
			src/init/camera.c 												\
			src/init/core_assets.c											\
			src/init/fight_menu.c											\
			src/init/game.c													\
			src/init/howtoplay_menu.c										\
			src/init/end_menu.c												\
			src/init/hud.c													\
			src/init/inventory.c											\
			src/init/level_up.c												\
			src/init/main_menu.c											\
			src/init/npc.c													\
			src/init/option_menu.c											\
			src/init/pause_menu.c											\
			src/init/player.c												\
			src/init/quest.c												\
			src/init/window.c												\
			src/render/render_core.c										\
			src/yml/loader.c                                                \
			src/yml/audio_loader.c                                          \
			src/yml/button_loader.c                                         \
			src/yml/scene_loader.c                                          \
			src/yml/texture_loader.c                                        \
			src/yml/text_loader.c                                           \
			src/yml/error/audio.c											\
			src/yml/error/button.c											\
			src/yml/error/text.c											\
			src/yml/error/texture.c											\
			src/utils/my_atoi.c												\
			src/utils/my_atob.c                                             \
			src/utils/get_next_line.c										\
			src/utils/my_strcpy.c                                           \
			src/utils/my_calloc.c                                           \
			src/utils/my_realloc.c                                          \
			src/utils/my_intlen.c                                           \
			src/utils/my_split.c                                            \
			src/utils/my_itoa.c                                             \
			src/utils/my_memset.c                                           \
			src/utils/my_revstr.c                                           \
			src/utils/my_strcat.c                                           \
			src/utils/my_strcmp.c                                           \
			src/utils/my_strdup.c                                           \
			src/utils/my_strlen.c                                           \

INC_DIR =	-I include									                    \
			-I include/loader							                    \
			-I lib/my_printf/include					                    \
			-I lib/my_cgraph/include					                    \
			-I lib/my_config/include					                    \

LIB_DIR =	-L lib/my_printf							                    \
			-L lib/my_cgraph							                    \
			-L lib/my_config							                    \

CC =		gcc

CFLAGS = 	-Wall -Wextra #-Werror -Wshadow

CPPFLAGS =	$(INC_DIR)

LDFLAGS	=	$(LIB_DIR) -lmyprintf -lmycgraph -lmyconfig -l csfml-audio -l csfml-system \
		-l csfml-graphics -l csfml-window -lm

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

.c.o:
		@echo -e "\033[95m[$(NAME)]\033[0m \033[92mCompiling \033[93m$<\033[0m...\033[0m"
		@$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $(<:.c=.o) $<

$(NAME):	$(OBJ)
		@$(MAKE) -s -C lib/my_printf/
		@$(MAKE) -s -C lib/my_cgraph/
		@$(MAKE) -s -C lib/my_config/
		@echo -en "\033[95m[$(NAME)]\033[0m \033[92mBuilding project...\033[0m"
		@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
		@echo -e "\033[92m Done.\033[0m"
clean:
		@$(MAKE) -s -C lib/my_printf/ clean
		@$(MAKE) -s -C lib/my_cgraph/ clean
		@$(MAKE) -s -C lib/my_config/ clean
		@echo -en "\033[95m[$(NAME)]\033[0m \033[92mCleaning files...\033[0m"
		@rm -f $(OBJ) *.gcno *.gcda vgcore.*
		@echo -e "\033[92m Done.\033[0m"

fclean: 	clean
		@$(MAKE) -s -C lib/my_printf/ fclean
		@$(MAKE) -s -C lib/my_cgraph/ fclean
		@$(MAKE) -s -C lib/my_config/ fclean
		@echo -en "\033[95m[$(NAME)]\033[0m \033[92mCleaning binary...\033[0m"
		@rm -f $(NAME)
		@echo -e "\033[92m Done.\033[0m"

re:		fclean all

build_lib:
		@echo -en "\033[95m[$(NAME)]\033[0m \033[92mBuilding library...\033[0m"
		@$(MAKE) -s -C lib/my_printf/
		@$(MAKE) -s -C lib/my_cgraph/
		@$(MAKE) -s -C lib/my_config/
		@echo -e "\033[92m Done.\033[0m"

valgrind:
		@$(MAKE) -s -C lib/my_printf/
		@$(MAKE) -s -C lib/my_cgraph/
		@$(MAKE) -s -C lib/my_config/
		@$(CC) -g $(SRC) $(CPPFLAGS) $(CFLAGS) -o $(NAME) $(LDFLAGS)

.PHONY: 	all clean fclean re build_lib valgrind
