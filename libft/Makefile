# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/21 16:48:26 by lramirez          #+#    #+#              #
#    Updated: 2017/09/15 15:29:11 by lararamirez      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB_SRC_DIR = ./sources/
LIB_OBJ_DIR = ./objects/
_LIB_OBJ =	ft_memalloc.o	ft_memdel.o		ft_strnew.o		ft_strdel.o		\
			ft_strclr.o		ft_putchar.o	ft_putstr.o		ft_putendl.o	\
			ft_putnbr.o		ft_putchar_fd.o	ft_putstr_fd.o	ft_putendl_fd.o \
			ft_putnbr_fd.o	ft_strlen.o		ft_isalpha.o	ft_isdigit.o	\
			ft_isalnum.o	ft_isascii.o	ft_isprint.o	ft_toupper.o	\
			ft_tolower.o	ft_memset.o		ft_bzero.o		ft_strequ.o		\
			ft_strnequ.o	ft_strdup.o		ft_strcpy.o		ft_strncpy.o	\
			ft_strcat.o		ft_strncat.o	ft_memcpy.o		ft_memccpy.o	\
			ft_memmove.o	ft_memchr.o		ft_memcmp.o		ft_strchr.o		\
			ft_strrchr.o	ft_strcmp.o		ft_strncmp.o	ft_strstr.o		\
			ft_strnstr.o	ft_strsub.o		ft_strlcat.o	ft_atoi.o		\
			ft_strjoin.o	ft_isspace.o	ft_strtrim.o	ft_itoa.o		\
			ft_lstadd.o		ft_lstdel.o		ft_lstdelone.o	ft_lstiter.o	\
			ft_lstmap.o		ft_lstnew.o		ft_abs.o		ft_intlen.o		\
			ft_countwords.o	ft_strtabnew.o	ft_strsplit.o	ft_striter.o	\
			ft_striteri.o	ft_strmap.o		ft_strmapi.o	ft_strjoinfree.o\
			ft_strnjoinfree.o	ft_strdupfree.o		ft_insert_in_str.o		\
			ft_append_before.o	ft_append_after.o	ft_uitoa.o				\
			ft_ltoa.o			ft_ultoa.o			ft_lltoa.o				\
			ft_ulltoa.o			ft_lltoa_base.o		ft_ultoa_base.o			\
			ft_atoui.o			ft_imtoa.o			ft_uimtoa.o				\
			ft_abs_long.o		ft_abs_longlong.o	ft_abs_intmax.o			\
			ft_longlen.o		ft_longlonglen.o	ft_intmaxlen.o			\
			ft_match.o			ft_putstr_fd_count.o	ft_lstaddend.o		\
			ft_putnstr_fd_count.o	ft_put_partial_str_count.o				\
			ft_hex_prefix.o 	ft_bin_prefix.o 	ft_oct_prefix.o 		\
			ft_create_padding.o	ft_pow.o	ft_dtoa.o	ft_fmod.o			\
			ft_create_null_string.o			ft_create_zero_string.o			\
			ft_is_empty_str.o	ft_wclen.o	ft_wcslen.o	ft_wctomb.o			\
			ft_wcstombs.o		ft_strsubfree.o		ft_kill.o				\
			ft_tab_quicksort.o	ft_tabcpy.o									\
			get_next_line.o													\
			a_populate_list.o												\
			b_determine_type.o												\
			c_get_arg.o														\
			d_compute_arg.o													\
			e_output_ft_asprintf.o											\
			e_output_ft_printf.o											\
			parsing_tools.o													\
			ft_printf.o
LIB_OBJ = $(patsubst %, $(LIB_OBJ_DIR)%, $(_LIB_OBJ))

CFLAGS = -Wall -Wextra -Werror -O3
VPATH = sources:includes

$(LIB_OBJ_DIR)%.o : $(LIB_SRC_DIR)%.c
	@cc $(CFLAGS) -c -Iincludes -o $@ $<

all: $(NAME)

$(NAME) : $(LIB_OBJ)
	@ar rc $(NAME) $(LIB_OBJ)
	@ranlib $(NAME)

$(LIB_OBJ) : ./includes/libft.h | $(LIB_OBJ_DIR)

$(LIB_OBJ_DIR) :
	@mkdir $(LIB_OBJ_DIR)

clean:
	@rm -rf $(LIB_OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
