/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:53:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/12 13:24:32 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
	char	**numbers;
}	t_data;

void check_for_invalid_char(char **ints);
void check_for_non_int(char **ints);
void check_for_doubles(char **ints);
#endif