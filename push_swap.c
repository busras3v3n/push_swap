/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/12 14:18:25 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number_count(char **argv)
{
	int count;
	int	i;
	char **temp;

	count = 0;
	i = 1;
	while(argv[i])
	{
		temp = ft_split(argv[i], ' ');
		count += get_2d_length(temp);
		free_2d_arr(temp);
		i++;
	}
	return(count);
}
void	init_data_numbers(char **argv, t_data *data)
{
	char	**temp;
	int		n;
	int		i;
	int		k;

	i = 1;
	n = 0;
	data->numbers = ft_calloc(check_number_count(argv) + 1, sizeof(char *));
	while(argv[i])
	{
		k = 0;
		temp = ft_split(argv[i], ' ');
		while(temp[k])
		{
			data->numbers[n] = temp[k];
			n++;
			k++;
		}
		free(temp);
		i++;
	}	
}
void	check_arguments(char **numbers, t_data *data)
{
	check_for_invalid_char(numbers, data);
	check_for_non_int(numbers, data);
	check_for_doubles(numbers, data);
}
int main(int argc, char **argv)
{
	t_data *data;
	int i;
	i = 0;

	data = ft_calloc(1, sizeof(t_data));
	if(argc >= 2)
	{
		init_data_numbers(argv, data);
		check_arguments(data->numbers, data);
		while(data->numbers[i])
		{
			ft_printf("%s", data->numbers[i]);
			i++;
		}
	}
	else
		write(2, "Error\nno arguments\n", 19);
}