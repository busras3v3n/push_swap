# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 09:59:40 by busseven          #+#    #+#              #
#    Updated: 2025/02/26 20:39:29 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= 	./format.c ./utils.c ./linked_list_utils.c ./linked_list_utils2.c ./moves.c ./moves2.c ./init_utils.c ./turk.c \
				./cost_calculation_utils.c ./linked_list_utils3.c ./set_attributes.c ./set_attributes_b.c ./turk_utils.c ./format_2.c
MAIN		=	./push_swap.c
BONUS_SRC	=	./bonus/checker_bonus.c ./bonus/moves_bonus.c ./bonus/moves2_bonus.c ./bonus/utils_bonus.c
OBJS 		= $(SRC:.c=.o)
MAIN_OBJ	= $(MAIN:.c=.o)
BONUS_OBJS	= $(BONUS_SRC:.c=.o)
BONUS_NAME	= checker
NAME 		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFTPRINTF	= ./ft_printf/libftprintf.a
LFLAGS		= -Lft_printf
LIBS		= $(LIBFTPRINTF)

all: $(LIBFTPRINTF) $(NAME)

$(NAME): $(MAIN_OBJ) $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) -o $(NAME) $(LFLAGS) $(LIBS)

$(LIBFTPRINTF):
	$(MAKE) -C ./ft_printf all

bonus: $(BONUS_OBJS) $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LFLAGS) $(LIBS)

fclean: clean
	make -C ./ft_printf fclean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

clean:
	rm -f $(OBJS)
	rm -f $(MAIN_OBJ)
	rm -f $(BONUS_OBJS)
	make -C ./ft_printf clean

re: fclean all

.PHONY: all clean fclean re bonus