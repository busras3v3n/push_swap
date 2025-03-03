/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:32:54 by busseven          #+#    #+#             */
/*   Updated: 2025/03/03 18:12:18 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	is_all_space_or_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '+' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

void	check_for_empty_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (is_all_space_or_sign(argv[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
