# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 17:30:33 by elhampto          #+#    #+#              #
#    Updated: 2019/06/03 22:51:03 by elhampto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = checks \
convers_dicsx \
convers_poufx \
flags \
ft_printf \
flags_2 \

LIB = ft_atoi \
	ft_is_space \
	ft_isdigit \
	ft_itoa_base_unsigned \
	ft_itoa_base \
	ft_itoa_cx \
	ft_itoa_float \
	ft_itoa_h \
	ft_itoa_hh \
	ft_itoa_ll \
	ft_itoa_long \
	ft_itoa_o_unsigned \
	ft_itoa_u_p \
	ft_itoa_unsigned \
	ft_itoa_x \
	ft_itoa \
	ft_memalloc \
	ft_numlen \
	ft_putchar \
	ft_putnbr \
	ft_putstr \
	ft_strcat \
	ft_strcmp \
	ft_strcpy \
	ft_strjoin \
	ft_strlen \
	ft_strnew \
	ft_tabs

INC = ft_printf.h

VPATH = lib_fun:files:inclu

OBJ_DOR = obj

OBJ = $(addsuffix .o, $(addprefix $(OBJ_DOR)/, $(SRC)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DOR)/, $(LIB)))

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INC)

all: $(OBJ_DOR) $(NAME)

$(OBJ_DOR):
	@echo "\033[32mmaking objects...\033[0m"
	@mkdir -p $(OBJ_DOR)

$(OBJ_DOR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[32mmaking lib...\033[0m"
	@ar -rcs $@ $^

clean:
	@echo "\033[33mcleaning libft repository...\033[0m"
	@/bin/rm -rf $(OBJ_DOR)

fclean: clean
	@echo "\033[33mremoving libft library file...\033[0m"
	@/bin/rm -rf $(OBJ_DOR)
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
