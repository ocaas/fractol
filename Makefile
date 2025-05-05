# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 01:37:44 by olopez-s          #+#    #+#              #
#    Updated: 2025/05/05 05:57:14 by olopez-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = fractol

SRC_DIR = src
SRC = \
	src/main.c	\
	src/utils.c	\
	src/utils2.c	\
	src/mandelbrot.c	\
	src/julia.c	\
	src/render.c	\
	src/hook.c	\
	src/input.c

CFLAGS = -Wall -Wextra -Werror -Iinclude -I./minilibx-linux

MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re