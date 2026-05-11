# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/30 17:30:27 by boschwie          #+#    #+#              #
#    Updated: 2026/02/02 10:04:45 by boschwie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT		:= \033[0m
BOLD		:= \033[1m

BLUE		:= \033[34m
CYAN		:= \033[36m
GREEN		:= \033[32m
MAGEN		:= \033[35m
RED			:= \033[31m
YELL		:= \033[1;33m

DONE		:= ✅

ARGS		?= maps/nether.cub

NAME		:= cub3d

SRC_DIR		:= src

SRC			:= core/main.c							\
			   core/error.c							\
			   core/cleanup.c						\
			   core/cleanup_utils.c					\
			   core/init.c							\
			\
			   game/player.c						\
			   game/player_utils.c					\
			   game/game.c							\
			   game/input_handlers.c				\
			   game/player_movement.c				\
			   game/player_rotation.c				\
			\
			   parsing/parser.c						\
			   parsing/parser_rgb.c					\
			   parsing/parser_config.c		\
			   parsing/parser_config_utils.c		\
			   parsing/parser_config_validation.c	\
			   parsing/parser_map.c					\
			   parsing/map_validator.c				\
			   parsing/arguments.c					\
			   parsing/line_utils.c					\
			   parsing/map_reader.c					\
			   parsing/map_reader_utils.c			\
			   parsing/map_builder.c				\
			   parsing/map_utils.c					\
			\
			   rendering/renderer.c					\
			   rendering/raycast.c					\
			   rendering/raycast_utils.c			\
			   rendering/raycast_init.c				\
			   rendering/raycast_init_utils.c		\
			   rendering/raycast_core.c				\
			   rendering/texture.c					\
			   rendering/texture_mapping.c			\
			   rendering/texture_mapping_utils.c	\
			   rendering/hotbar.c					\
			\
			   utils/string_utils.c					\
			   utils/char_utils.c					\
			   utils/array_utils.c					\
			\

SRC			:= $(SRC:%=$(SRC_DIR)/%)

INC			:= inc inc/core inc/game inc/parsing inc/rendering \
			   inc/utils inc/config

MLX_REPO	:= https://github.com/42Paris/minilibx-linux.git
MLX_DIR		:= mlx_linux
MLX_TARGET	:= $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS	:= -L $(MLX_DIR) -lmlx_Linux -lX11 -lXext

LIBFT_DIR	:= libft
LIBFT_TARGET:= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	:= -L $(LIBFT_DIR) -lft

LIBS		:= $(MLX_TARGET) $(LIBFT_TARGET)
LIB_DIRS	:= $(MLX_DIR) $(LIBFT_DIR)

BUILD_DIR	:= build
OBJ			:= $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
INC_FLAGS	:= $(INC:%=-I%)

LDFLAGS		:= -L $(MLX_DIR) -L $(LIBFT_DIR)
LDLIBS		:= $(MLX_FLAGS) $(LIBFT_FLAGS) -lm

MAKEFLAGS	+= --silent --no-print-directory

# Generates .d dependency files alongside .o files
DEPFLAGS	:= -MMD -MP

all		: $(NAME)

$(MLX_TARGET):
	printf "%-60b" "Compiling $(BOLD)MiniLibX... $(DEFAULT)"
	git clone $(MLX_REPO) $(MLX_DIR) 2> /dev/null
	$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	echo "$(GREEN)$(DONE)$(DEFAULT)"

$(LIBFT_TARGET):
	printf "%-60b" "Compiling $(BOLD)libft... $(DEFAULT)"
	$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
	echo "$(GREEN)$(DONE)$(DEFAULT)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	printf "%-60b" \
		"Compiling $(BOLD)$(patsubst $(SRC_DIR)/%,%,$<)... $(DEFAULT)"
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEPFLAGS) -MF $(@:.o=.d) $(INC_FLAGS) -o $@ -c $<
	echo "$(GREEN)$(DONE)$(DEFAULT)"

$(NAME): $(LIBS) $(OBJ)
	printf "%-60b" \
		"Compiling $(BOLD)$@... $(DEFAULT)"
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)
	echo "$(GREEN)$(DONE)$(DEFAULT)"

bonus	: all

clean	:
	printf "%-55b" "$(RED)Deleting $(BOLD)objects... $(DEFAULT)"
	rm -rf $(BUILD_DIR)
	@if [ -d "$(LIB_DIRS)" ]; then \
		$(MAKE) clean -C $(MLX_DIR) > /dev/null; \
		$(MAKE) clean -C $(LIBFT_DIR) > /dev/null; \
	fi
	echo "$(GREEN)$(DONE)$(DEFAULT)"

fclean	: clean
	printf "%-55b" "$(RED)Deleting $(BOLD)executables... $(DEFAULT)"
	@if [ -d "$(MLX_DIR)" ]; then \
		rm -rf $(MLX_DIR); \
	fi
	@if [ -d "$(LIBFT_DIR)" ]; then \
		$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null; \
	fi
	rm -f $(NAME)
	echo "$(GREEN)$(DONE)$(DEFAULT)"

re		: fclean all

run		: all
	./$(NAME) $(ARGS)

runv	: all
	valgrind \
		--leak-check=full --show-leak-kinds=all --track-fds=all	\
		--track-origins=yes --suppressions=valgrind.supp	\
		./$(NAME) $(ARGS)

norm	:
	printf "%-55b" "Checking $(BOLD)Norminette $(DEFAULT)...";
	NORM_OUTPUT=$$(norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(INC) 2>&1); \
	ERRORS=$$(echo "$$NORM_OUTPUT" | grep -Ew "\w*.c: E|Error" || true); \
	if [ -n "$$ERRORS" ]; then \
		echo ""; \
		echo "$$ERRORS" | grep -Ew "\w*.c: E|Error" --color="always"; \
	else \
		echo "" ;\
		printf "%-55b" "👏$(BOLD)$(GREEN) Norm is okay$(DEFAULT)"; \
		echo "$(GREEN)$(DONE)$(DEFAULT)"; \
	fi

.PHONY: all bonus clean fclean re run runv norm

# Include generated dependency files
-include $(OBJ:.o=.d)
