/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:04:50 by busseven          #+#    #+#             */
/*   Updated: 2025/02/26 20:38:20 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	check_if_int(char *str)
{
	char	*cmp;
	int		i;
	int		diff;

	i = 0;
	if (str[i] == '-')
		cmp = "-2147483648";
	else if (str[i] == '+')
		cmp = "+2147483647";
	else
		cmp = "2147483647";
	diff = ft_strlen(str) - ft_strlen(cmp);
	if (diff > 0)
		return (0);
	else if (diff == 0)
	{
		while (str[i])
		{
			if (str[i] > cmp[i])
				return (0);
			i++;
		}
	}
	return (1);
}

void	check_for_doubles(char **argv, t_data *data)
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

void	check_for_invalid_char(char **argv, t_data *data)
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

void	check_for_non_int(char **argv, t_data *data)
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
