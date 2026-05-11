# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 19:53:35 by bschwiet          #+#    #+#              #
#    Updated: 2026/02/01 16:35:03 by boschwie         ###   ########.fr        #
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
WRONG		:= ❌

NAME		:= libft.a

FLAGS_FILE	:= compile_flags.txt

# Source directories
SRC_DIR		:= srcs
CORE_DIR	:= $(SRC_DIR)/core
STRING_DIR	:= $(SRC_DIR)/string
MEMORY_DIR	:= $(SRC_DIR)/memory
LIST_DIR	:= $(SRC_DIR)/list
IO_DIR		:= $(SRC_DIR)/io
PRINTF_DIR	:= $(SRC_DIR)/printf
GNL_DIR		:= $(SRC_DIR)/gnl

# Source files by category
CORE_SRC	:= isalpha.c isdigit.c isalnum.c isascii.c isprint.c \
			   toupper.c tolower.c atoi.c itoa.c

STRING_SRC	:= strlen.c strchr.c strrchr.c strncmp.c strnstr.c \
			   strdup.c substr.c strjoin.c strtrim.c strlcpy.c \
			   strlcat.c split.c strmapi.c striteri.c

MEMORY_SRC	:= memset.c bzero.c memcpy.c memmove.c memchr.c \
			   memcmp.c calloc.c

LIST_SRC	:= lstnew.c lstadd_front.c lstsize.c lstlast.c \
			   lstadd_back.c lstdelone.c lstclear.c lstiter.c lstmap.c

IO_SRC		:= putchar_fd.c putstr_fd.c putendl_fd.c putnbr_fd.c

PRINTF_SRC	:= printf.c printf_hex.c printf_p.c printf_un.c printf_utils.c

GNL_SRC		:= get_next_line.c get_next_line_utils.c handle_stash.c

# Add directory prefixes
CORE_SRC	:= $(CORE_SRC:%=$(CORE_DIR)/%)
STRING_SRC	:= $(STRING_SRC:%=$(STRING_DIR)/%)
MEMORY_SRC	:= $(MEMORY_SRC:%=$(MEMORY_DIR)/%)
LIST_SRC	:= $(LIST_SRC:%=$(LIST_DIR)/%)
IO_SRC		:= $(IO_SRC:%=$(IO_DIR)/%)
PRINTF_SRC	:= $(PRINTF_SRC:%=$(PRINTF_DIR)/%)
GNL_SRC		:= $(GNL_SRC:%=$(GNL_DIR)/%)

ALL_SRC		:= $(CORE_SRC) $(STRING_SRC) $(MEMORY_SRC) $(LIST_SRC) $(IO_SRC) $(PRINTF_SRC) $(GNL_SRC)

INC			:= includes

BUILD_DIR	:= build
OBJ			:= $(ALL_SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= $(INC:%=-I%)

MAKEFLAGS	+= --silent --no-print-directory

all		: $(NAME)

$(FLAGS_FILE):
	echo "Generating $(BOLD)$(FLAGS_FILE)...$(DEFAULT)"
	echo "$(CFLAGS:%=%\n)" > $(FLAGS_FILE)
	echo "$(CPPFLAGS:%=%\n)" >> $(FLAGS_FILE)

# Pattern rule for all subdirectories
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	printf "%-50b" "Compiling $(BOLD)$(patsubst $(SRC_DIR)/%,%,$<)... $(DEFAULT)"
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	echo "$(GREEN)$(DONE)$(DEFAULT)"

$(NAME):  $(FLAGS_FILE) $(OBJ)
	printf "%-50b" "Creating $(BOLD)$@... $(DEFAULT)"
	ar rcs $(NAME) $(OBJ)
	echo "$(GREEN)$(DONE)$(DEFAULT)"

clean	:
	printf "%-55b" "$(RED)Deleting $(BOLD)objects... $(DEFAULT)"
	rm -rf $(BUILD_DIR)
	rm -rf $(FLAGS_FILE)
	echo "$(GREEN)$(DONE)$(DEFAULT)"

fclean	: clean
	printf "%-55b" "$(RED)Deleting $(BOLD)$(NAME)... $(DEFAULT)"
	rm -f $(NAME)
	echo "$(GREEN)$(DONE)$(DEFAULT)"

re		: fclean all

norm	:
	printf "%-55b" "Checking $(BOLD)Norminette $(DEFAULT)...";
	NORM_OUTPUT=$$(norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(INC) 2>&1); \
	ERRORS=$$(echo "$$NORM_OUTPUT" | grep -Ew "\w*.c: E|Error|\w*.h: E|Error" || true); \
	if [ -n "$$ERRORS" ]; then \
		echo ""; \
		echo "$$ERRORS" | grep -Ew "\w*.c: E|Error|\w*.h: E|Error" --color="always"; \
	else \
		echo "" ;\
		printf "%-55b" "👏$(BOLD)$(GREEN) Norm is okay !$(DEFAULT)"; \
		echo "$(GREEN)$(DONE)$(DEFAULT)"; \
	fi

.PHONY: all clean fclean re norm
