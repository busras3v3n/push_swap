/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/12 13:41:47 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_format(char **ints)
{
	check_for_invalid_char(ints);
	check_for_non_int(ints);
	check_for_doubles(ints);
	return(0);
}
int	get_2d_length(char **arr)
{
	int	i;
	
	i = 0;
	while(arr[i])
		i++;
	return(i);
}
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
		free(temp);
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
void	check_arguments(char **numbers)
{
	check_for_invalid_char(numbers);
	check_for_non_int(numbers);
	check_for_doubles(numbers);
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
		check_arguments(data->numbers);
		while(data->numbers[i])
		{
			ft_printf("%s", data->numbers[i]);
			i++;
		}
	}
	else
		write(2, "Error\nno arguments\n", 19);
}