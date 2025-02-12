/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/12 18:17:02 by busseven         ###   ########.fr       */
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
		turk(data);
		while(data->a[0])
		{
			ft_printf("number: %d, index: %d, target_index: %d\n", data->a[0]->content, data->a[0]->index, data->a[0]->target);
			data->a[0] = data->a[0]->next;
		}
		ft_printf("\n");
		while(data->b[0])
		{
			ft_printf("number: %d, index: %d, target_index: %d\n", data->b[0]->content, data->b[0]->index, data->b[0]->target);
			data->b[0] = data->b[0]->next;
		}
		free_data_exit(data);
	}
	else
		write(2, "Error\nno arguments\n", 19);
}