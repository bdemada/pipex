# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 16:39:55 by bde-mada          #+#    #+#              #
#    Updated: 2023/06/07 12:45:39 by bde-mada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex

define ASCIIART
             _
            |▓|    _
            |▓|===(#)    //////
            |▓|    | \  | - - |
                    \ \ (  c  )            ____
                     \ \ \ = /            /___/\_
                      |──|█──|           ||   \_/|
                      |  |█  |           ||   | |/
                      |  |█  |      /....||___|/ ══/
                      |______|     /....          /▒
                       |░|░|      /══════════════/ ▒
                       |░|░|       ▒  ▒         ▒  ▒
                       |░|░|       ▒  ▒         ▒  ▒
───────────────────────|░|░|───────▒──▒─────────▒──▒────
                       |_____>     ▒            ▒

endef
export ASCIIART

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pedantic

#Optimization and valgrind debugging flags:
LNK			:= -g3 -O0 # -fsanitize=address
#change -O0 with -O1 or -O2 for faster execution but worse info

LDFLAGS		= $(addprefix -L, $(LIBS_DIR))
LDLIBS		= $(addprefix -l, $(LIBS))
INC			= -I$(INC_DIR) -Ilib/libft

SRC_DIR		= src/
OBJ_DIR		= obj/
INC_DIR		= include/

LIBS		= ft
INCLUDE		= pipex.h pipex_bonus.h
SRC_FILES	= pipex.c pipex_utils.c open_files.c terminate.c split_args.c
SRC_FILES_BONUS	= pipex_bonus.c pipex_utils.c here_doc.c terminate.c split_args.c

#pipex.c pipex_utils.c

OBJ_FILES 	= $(SRC_FILES:.c=.o)
OBJ_FILES_BONUS 	= $(SRC_FILES_BONUS:.c=.o)

LIBS_DIR	= $(addprefix lib/lib, $(LIBS))
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))
SRCS_BONUS	= $(addprefix $(SRC_DIR), $(SRC_FILES_BONUS))
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJS_BONUS	= $(addprefix $(OBJ_DIR), $(OBJ_FILES_BONUS))
INCLUDES	= $(addprefix $(INC_DIR), $(INCLUDE))

NONE		:= "\033[0m"
GREEN		:= "\033[32m"
YELLOW		:= "\033[1;33m"
GRAY		:= "\033[2;37m"
CURSIVE		:= "\033[3m"
RED			:= "\x1b[31m"
BLUE		:= "\033[1;34m"
CYAN 		:= "\033[1;36m"
ACCENT		:= "\033[92;3;4;1m"

all: $(LIBS) obj $(NAME)

obj:
	@echo $(CURSIVE)$(GRAY) "		- Creating object directory..." $(NONE)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(INCLUDES)
	@echo $(CURSIVE)$(GRAY) "		- Making object files..." $(NONE)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDES)
	@echo $(CURSIVE)$(GRAY) "		- Compiling project $(NAME)..." $(NONE)
	$(CC) $(CFLAGS) $(LNK) $(LDFLAGS) $(LDLIBS) $(INC) $(OBJS) -o $(NAME)
	@echo $(ACCENT)"✅ $(NAME) compiled ✅"$(NONE)
	@echo $(RED)"$$ASCIIART"$(NONE)

$(LIBS): $(LIBS_DIR)
	@make -sC lib/libft

bonus: $(LIBS) obj $(OBJS_BONUS) $(INCLUDES)
	@echo $(CURSIVE)$(GRAY) "		- Compiling project $(NAME)..." $(NONE)
	$(CC) $(CFLAGS) $(LNK) $(LDFLAGS) $(LDLIBS) $(INC) $(OBJS_BONUS) -o $(NAME)
	@echo $(ACCENT)"✅ $(NAME) compiled ✅"$(NONE)
	@echo $(RED)"$$ASCIIART"$(NONE)

clean: $(LIBS_DIR)
	@make clean -sC $<
	@rm -Rf $(OBJ_DIR)
	@echo $(RED) Objects deleted!$(NONE) 🗑

fclean: $(LIBS_DIR)
	@make fclean -sC $<
	@rm -Rf $(NAME) $(OBJ_DIR)
	@echo $(RED) "Objects & $(NAME) executable deleted!"$(NONE) 🗑❌

norm:
	@norminette include lib src
	@echo $(ACCENT)"✅ $(NAME) norm OK ✅"$(NONE)

re: fclean all

.phony: all clean fclean re norm

# List all the used functions to check if there is a forbidden one:
#objdump -t obj/* | grep "*UND*" | awk '{print $3}' | sort -u
