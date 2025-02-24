/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:22:53 by busseven          #+#    #+#             */
/*   Updated: 2025/02/24 12:25:55 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	check_for_doubles_bonus(char **argv, t_data *data)
{
	int	i;
	int	n;

	i = 0;
	while (argv[i])
	{
		n = 1;
		while (argv[n])
		{
			if (i != n && ft_atoi(argv[i]) == ft_atoi(argv[n]))
			{
				write(2, "Error\n", 6);
				free_data_exit(data, 1);
			}
			n++;
		}
		i++;
	}
}

void	check_for_invalid_char_bonus(char **argv, t_data *data)
{
	int	i;
	int	n;

	i = 0;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (is_sign(argv[i][n]) && n == 0)
				;
			else if (!ft_isdigit(argv[i][n]))
			{
				write(2, "Error\n", 6);
				free_data_exit(data, 1);
			}
			n++;
		}
		i++;
	}
}

void	check_for_non_int_bonus(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!check_if_int(argv[i]))
		{
			write(2, "Error\n", 6);
			free_data_exit(data, 1);
		}
		i++;
	}
}
void	check_arguments_bonus(char **numbers, t_data *data)
{
	check_for_invalid_char_bonus(numbers, data);
	check_for_non_int_bonus(numbers, data);
	check_for_doubles_bonus(numbers, data);
}