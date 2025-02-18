/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/18 13:15:48 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_data *data)
{
	t_list	*max;

	max = find_biggest(*(data->a));
	if (ft_lstsize(*(data->a)) == 2)
	{
		if (data->a[0]->index > data->a[0]->next->index)
			swap(data->a, "a");
	}
	if (ft_lstsize(*(data->a)) == 3)
	{
		if (ft_lstlast(*(data->a)) != max)
		{
			if (max->index == data->a[0]->index)
				rotate(data->a, "a");
			else
				reverse_rotate(data->a, "a");
		}
		if (data->a[0]->index > data->a[0]->next->index)
			swap(data->a, "a");
	}
}

void	small_sort(t_data *data)
{
	if (!check_ordered_circular(*(data->a)))
	{
		push(data->a, data->b, "b");
		if (ft_lstsize(*(data->a)) > 3)
			push(data->a, data->b, "b");
		tiny_sort(data);
		turk(data);
	}
}

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

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (argc >= 2)
	{
		init_data(data, argv);
		if (ft_lstsize(*(data->a)) == 1)
			return (0);
		else if (ft_lstsize(*(data->a)) < 4)
			tiny_sort(data);
		else if (ft_lstsize(*(data->a)) == 4 || ft_lstsize(*(data->a)) == 5)
			small_sort(data);
		else
			turk(data);
		free_data_exit(data, 0);
	}
	else
		write(2, "Error\nno arguments\n", 19);
}
