/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/12 15:08:50 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data, char **argv)
{
	init_data_numbers(argv, data);
	check_arguments(data->numbers, data);
	data->a = ft_calloc(1, sizeof(t_list **));
	data->b = ft_calloc(1, sizeof(t_list **));
	put_nodes_in_a(data->a, data->numbers);
	set_real_index(data->a);
}
int main(int argc, char **argv)
{
	t_data *data;
	int i;
	i = 0;

	data = ft_calloc(1, sizeof(t_data));
	if(argc >= 2)
	{
		init_data(data, argv);
		while(data->numbers[i])
		{
			ft_printf("%s", data->numbers[i]);
			i++;
		}
	}
	else
		write(2, "Error\nno arguments\n", 19);
}