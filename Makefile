# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 12:48:53 by moamzil           #+#    #+#              #
#    Updated: 2023/09/01 10:30:57 by moamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	= -Wall -Wextra -Werror -fsanitize=address -g
CC		= cc
AR		= ar cr
RM		= rm -rf
NAME	= push_swap
BIN		= bin
FILE	= $(addprefix $(BIN)/, main arg_check tools check_sorted ft_operations_1 ft_operations_2 ft_operations_3 push_swap ft_sort_3 ft_sort_5 ft_sort_100 ft_sort_500 tools_2)
HEAD	= include/push_swap.h
LIBFT	= src/libft
PRINTF	= src/ft_printf
SRC		= src/libft/libft.a src/ft_printf/ft_printf.a
OBJ		= $(FILE:=.o)
ARC		= bin/p_s.a
CLN		= make clean -C
FLN		= make fclean -C

all: $(ARC) $(SRC)
	@$(CC) $(FLAGS) $(SRC) $(ARC) -o $(NAME)

$(ARC): $(OBJ)
	@$(AR) $(ARC) $(OBJ)

$(SRC):
	@make -C $(LIBFT)
	@make -C $(PRINTF)

%.o: %.c $(HEAD)
	@$(CC) $(FLAFGS) -c $< -o $@

clean:
	@$(RM) $(ARC)
	@$(RM) $(OBJ)
	@$(CLN) $(LIBFT)
	@$(CLN) $(PRINTF)

fclean: clean
	@$(RM) $(NAME)
	@$(FLN) $(LIBFT)
	@$(FLN) $(PRINTF)

re: fclean all
Phony: all clean fclean re
