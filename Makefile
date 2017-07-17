# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschramm <rschramm@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 14:23:11 by rschramm          #+#    #+#              #
#    Updated: 2017/05/16 09:58:34 by rschramm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = filler

CC = gcc

FLAG += -Wall -Werror -Wextra

SRC = ./srcs/main.c \
	  
OBJ = $(SRC:.c=.o)

LIBFT = libft/libftprintf.a \
		srcs/make_heat_map.c \
		srcs/get_board_piece_meta.c \
		srcs/find_safe_spot.c \
		srcs/get_helpers.c \
		srcs/value.c \
		srcs/fill_trail.c \

all: $(NAME)

$(NAME): $(OBJ)
	@make re -C libft
	@gcc $(FLAG) -o $(NAME) $(SRC) $(LIBFT) -g
	@echo "\033[33;32mSystem Ready >:D"

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "\033[33mCleaned..."

fclean:
	@make clean
	@make fclean -C libft
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "\033[31mfCleaned..."

re: fclean all
