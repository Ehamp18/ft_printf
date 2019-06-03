# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 17:30:33 by elhampto          #+#    #+#              #
#    Updated: 2019/05/29 10:47:57 by elhampto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = checks \
convers_dicsx \
convers_poufx \
flags \
ft_printf \
flags_2 \

LIBFT_D = ./libft/
LIB = libft/libft.a

INC = ft_printf.h

VPATH = libft:files:inclu

OBJ_DOR = obj

OBJ = $(addsuffix .o, $(addprefix $(OBJ_DOR)/, $(SRC)))

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INC)

all: $(LIB) $(OBJ_DOR) $(NAME)

$(LIB):
	@make -C $(LIBFT_D)

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
	@make clean -C $(LIBFT_D)
	@/bin/rm -rf $(OBJ_DOR) $(DEP)

fclean: clean
	@echo "\033[33mremoving libft library file...\033[0m"
	@make fclean -C $(LIBFT_D)
	@/bin/rm -rf $(OBJ_DIR)
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
