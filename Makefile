# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 09:59:40 by busseven          #+#    #+#              #
#    Updated: 2025/02/12 14:02:45 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= 	./push_swap.c ./format.c ./utils.c ./linked_list_utils.c
OBJS 		= $(SRC:.c=.o)
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

fclean: clean
	make -C ./ft_printf fclean
	rm -rf $(NAME)

clean:
	rm -f $(OBJS)
	make -C ./ft_printf clean

re: fclean all

.PHONY: all clean fclean re bonus