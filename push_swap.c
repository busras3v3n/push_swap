/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/15 20:10:34 by busseven         ###   ########.fr       */
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
	set_real_index(data->a[0]);
	set_real_index(data->b[0]);
	set_lstsizes(data->a);
	set_directions_list(*(data->a));
}
int main(int argc, char **argv)
{
	t_data *data;

	data = ft_calloc(1, sizeof(t_data));
	if(argc >= 2)
	{
		init_data(data, argv);
		turk(data);
		while(*(data->a))
		{
			ft_printf("%d, target: %d, rr: %d, rrr: %d, cost: %d\n", data->a[0]->content, data->a[0]->target->content, data->a[0]->rr, data->a[0]->rrr, data->a[0]->cost);
			*(data->a) = data->a[0]->next;
		}
		while(*(data->b))
		{
			ft_printf("%d\n", data->b[0]->content);
			*(data->b) = data->b[0]->next;
		}
		free_data_exit(data);
	}
	else
		write(2, "Error\nno arguments\n", 19);
}