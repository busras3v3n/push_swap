/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:36 by busseven          #+#    #+#             */
/*   Updated: 2025/03/06 13:05:17 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_until_sorted(t_data *data)
{
	t_list	*min;

	min = find_smallest(*(data->a));
	while (*(data->a) != min)
	{
		if (min->direction == 0)
			rotate(data->a, "a");
		else
			reverse_rotate(data->a, "a");
	}
}

void	get_nodes_to_top_atob(t_data *data, t_list *a, t_list *b)
{
	if (a->rr == 0 && a->rrr == 0)
		rotate_individually(data, a, b);
	else if (a->rr == 1)
		rotate_together(data, a, b);
	else if (a->rrr == 1)
		reverse_rotate_together(data, a, b);
}

void	get_nodes_to_top_btoa(t_data *data, t_list *b, t_list *a)
{
	if (b->rr == 0 && b->rrr == 0)
		rotate_individually(data, a, b);
	else if (b->rr == 1)
		rotate_together(data, a, b);
	else if (b->rrr == 1)
		reverse_rotate_together(data, a, b);
}

void	turk(t_data *data)
{
	t_list	*cheapest;

	if (!check_ordered_circular(*(data->a)))
		push(data->a, data->b, "b");
	if (!check_ordered_circular(*(data->a)))
		push(data->a, data->b, "b");
	while (!check_ordered_circular(*(data->a)) && ft_lstsize(*(data->a)) > 3)
	{
		set_attributes_a(data->a, data->b);
		cheapest = find_cheapest_node(*(data->a));
		get_nodes_to_top_atob(data, cheapest, cheapest->target);
		push(data->a, data->b, "b");
	}
	if(ft_lstsize(*(data->a)) <= 3)
		tiny_sort(data);
	while (*(data->b))
	{
		set_attributes_b(data->b, data->a);
		cheapest = find_cheapest_node(*(data->b));
		get_nodes_to_top_btoa(data, cheapest, cheapest->target);
		push(data->b, data->a, "a");
	}
	rotate_until_sorted(data);
}
