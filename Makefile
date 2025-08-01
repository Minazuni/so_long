# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 10:48:44 by ko-mahon          #+#    #+#              #
#    Updated: 2025/07/31 14:09:22 by ko-mahon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

NAME = so_long

SRCS = check_content.c error.c finish.c free.c main.c \
parsing_utils.c parsing_utils2.c parsing.c so_long.c touch.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(LIBFT_A) $(MLX_LIB) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -g $(OBJS) $(LIBFT_A) $(MLX_FLAGS) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
