/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:32:54 by busseven          #+#    #+#             */
/*   Updated: 2025/02/24 12:39:43 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	is_all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
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
		if (is_all_space(argv[i]) || argv[i][0] == '\0')
		{
			ft_printf("Error\nEmpty argument(s)\n");
			exit(1);
		}
		i++;
	}
}
