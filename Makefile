# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 16:14:52 by arimanuk          #+#    #+#              #
#    Updated: 2025/06/02 19:57:36 by arimanuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INC = ../so_long.h ../get_next_line.h

CC = cc
CFLAGS = -Wall -Wextra -Werror  -g3 -fsanitize=address

MLX_DIR = ./minilibx-linux

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lGL -lGLU

SRCS = main.c validation.c get_next_line.c get_next_line_utils.c \
		functions.c split.c check_functions.c flood_fill.c mlx.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@rm -rf $(OBJS)

.PHONY: all re clean fclean