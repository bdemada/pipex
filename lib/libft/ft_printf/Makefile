# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 15:41:01 by bde-mada          #+#    #+#              #
#    Updated: 2023/05/26 18:35:54 by bde-mada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# .SILENT:
# DO NOT PRINT THE EXECUTION MESSAGES

SRC_DIR		= src/
LIBFT_DIR	= libft/

SRC_FILES 	= ft_printf.c ft_printf_utils.c ft_putchar.c
OBJ_FILES	= $(SRC_FILES:.c=.o)

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))

LNK			= -0fast

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.phony: all clean fclean re