# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 17:30:33 by elhampto          #+#    #+#              #
#    Updated: 2019/07/17 19:38:18 by elhampto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = files/checks.c files/dispatch.c files/ft_printf.c conversions/con_per.c \
	conversions/con_b.c conversions/con_c.c conversions/con_d.c \
	conversions/con_i.c conversions/con_o.c conversions/con_p.c \
	conversions/con_s.c conversions/con_u.c conversions/con_x.c \
	conversions/con_xa.c lib_fun/ft_atoi.c lib_fun/ft_bzero.c \
	conversions/norm.c lib_fun/ft_strdup.c lib_fun/ft_cstrjoin.c \
	lib_fun/ft_is_space.c lib_fun/ft_isalpha.c lib_fun/ft_isdigit.c \
	lib_fun/ft_isint.c lib_fun/ft_itoa_b.c lib_fun/ft_itoa_base_unsigned.c \
	lib_fun/ft_itoa_base.c lib_fun/ft_itoa_cx.c lib_fun/ft_itoa_h.c \
	lib_fun/ft_itoa_hh.c lib_fun/ft_itoa_ll.c lib_fun/ft_itoa_long.c \
	lib_fun/ft_itoa_o_unsigned.c lib_fun/ft_itoa_u_p.c lib_fun/ft_ccstrjoin.c\
	lib_fun/ft_itoa_unsigned.c lib_fun/ft_itoa_x.c lib_fun/ft_itoa.c \
	lib_fun/ft_memalloc.c lib_fun/ft_memset.c lib_fun/ft_numlen.c \
	lib_fun/ft_putchar.c lib_fun/ft_putnbr.c lib_fun/ft_putstr.c \
	lib_fun/ft_strcat.c lib_fun/ft_strcmp.c lib_fun/ft_strcpy.c \
	lib_fun/ft_strjoin.c lib_fun/ft_strlen.c lib_fun/ft_strnew.c \
	lib_fun/ft_strrev_cpy.c lib_fun/ft_strsplit.c lib_fun/ft_strsub.c \
	lib_fun/ft_tabs.c lib_fun/ft_wordcount.c

OBJ = checks.o dispatch.o ft_printf.o con_per.o \
	con_b.o con_c.o con_d.o ft_strdup.o\
	con_i.o con_o.o con_p.o ft_cstrjoin.o\
	con_s.o con_u.o con_x.o norm.o ft_ccstrjoin.o\
	con_xa.o ft_atoi.o ft_bzero.o \
	ft_is_space.o ft_isalpha.o ft_isdigit.o \
	ft_isint.o ft_itoa_b.o ft_itoa_base_unsigned.o \
	ft_itoa_base.o ft_itoa_cx.o ft_itoa_h.o \
	ft_itoa_hh.o ft_itoa_ll.o ft_itoa_long.o \
	ft_itoa_o_unsigned.o ft_itoa_u_p.o \
	ft_itoa_unsigned.o ft_itoa_x.o ft_itoa.o \
	ft_memalloc.o ft_memset.o ft_numlen.o \
	ft_putchar.o ft_putnbr.o ft_putstr.o \
	ft_strcat.o ft_strcmp.o ft_strcpy.o \
	ft_strjoin.o ft_strlen.o ft_strnew.o \
	ft_strrev_cpy.o ft_strsplit.o ft_strsub.o \
	ft_tabs.o ft_wordcount.o

INC = inclu/ft_printf.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):
	@echo "\033[32mCreating library...\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@echo "\033[33mCleaning objects...\033[0m"
	@/bin/rm -rf $(OBJ)

fclean: clean
	@echo "\033[33mCleaning objects and library...\033[0m"
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
