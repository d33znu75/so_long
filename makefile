# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 22:39:34 by rhmimchi          #+#    #+#              #
#    Updated: 2024/01/24 18:45:28 by rhmimchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/so_long.c ./src/checker.c ./src/checker2.c ./src/get_next_line.c ./src/get_next_line_utils.c ./src/keys.c \
	./src/checker3.c ./src/window.c ./src/init.c ./src/map.c ./src/ft_putnbr_fd.c ./src/path.c
OBJ = $(SRC:.c=.o)

SRC_B = ./bonus/so_long_bonus.c ./bonus/checker_bonus.c ./bonus/checker2_bonus.c ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c ./bonus/keys_bonus.c \
	./bonus/checker3_bonus.c ./bonus/window_bonus.c ./bonus/init_bonus.c ./bonus/map_bonus.c ./bonus/ft_putnbr_fd_bonus.c ./bonus/path_bonus.c ./bonus/ft_itoa_bonus.c
OBJ_B = $(SRC_B:.c=.o)

NAME = so_long
NAME_B = so_long_bonus
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B)
	cc $(FLAGS) $(MLX) $(OBJ_B) -o $(NAME_B)

$(NAME): $(OBJ)
	cc $(FLAGS) $(MLX) $(OBJ) -o $(NAME)

%.o: %.c ./src/so_long.h ./bonus/so_long_bonus.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -rf $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re