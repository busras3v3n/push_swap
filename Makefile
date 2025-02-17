# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 09:59:40 by busseven          #+#    #+#              #
#    Updated: 2025/02/17 17:47:25 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= 	./push_swap.c ./format.c ./utils.c ./linked_list_utils.c ./linked_list_utils2.c ./moves.c ./moves2.c ./init_utils.c ./turk.c \
				./cost_calculation_utils.c ./linked_list_utils3.c ./set_attributes.c ./set_attributes_b.c ./turk_utils.c
BONUS_SRC	=	./bonus/checker_bonus.c ./bonus/moves_bonus.c ./bonus/moves2_bonus.c ./bonus/utils_bonus.c
OBJS 		= $(SRC:.c=.o)
BONUS_OBJS	= $(BONUS_SRC:.c=.o)
BONUS_NAME	= checker
NAME 		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFTPRINTF	= ./ft_printf/libftprintf.a
LFLAGS		= -Lft_printf
LIBS		= $(LIBFTPRINTF)

all: $(LIBFTPRINTF) $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS) $(LIBS)

$(LIBFTPRINTF):
	$(MAKE) -C ./ft_printf all

bonus: $(BONUS_OBJS) $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LFLAGS) $(LIBS)

fclean: clean
	make -C ./ft_printf fclean
	rm -rf $(NAME)

clean:
	rm -f $(OBJS)
	make -C ./ft_printf clean

re: fclean all

.PHONY: all clean fclean re bonus