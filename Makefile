# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/25 16:11:33 by lararamirez       #+#    #+#              #
#    Updated: 2017/09/25 19:01:21 by lararamirez      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

LIBFT = ./libft/libft.a
INCLUDES = ./lem_in_dir/includes/lem_in.h
SRC_DIR = ./lem_in_dir/sources/
OBJ_DIR = ./lem_in_dir/objects/
_OBJ =	main.o \
		get_rooms.o \
		error.o \
		other.o \
		tools.o
OBJ = $(patsubst %, $(OBJ_DIR)%, $(_OBJ))

CFLAGS = -Wall -Wextra -Werror -O3
VPATH = sources:includes

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@cc $(CFLAGS) -c -Iincludes -o $@ $<

all: make_libft $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ) : $(INCLUDES) | $(OBJ_DIR)

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

make_libft:
	@make -C ./libft

clean:
	@rm -rf $(OBJ_DIR)
	@make -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all

.PHONY: clean fclean re
