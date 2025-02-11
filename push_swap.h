/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:53:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/11 18:02:36 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>

typedef struct data
{
	int	size_a;
	int	size_b;
	int	*stack_a;
	int	*stack_b;
	int	*target_a;
	int	cost;
	int	rr;
	int	rrr;
}	t_data;
#endif