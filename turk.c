/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:36 by busseven          #+#    #+#             */
/*   Updated: 2025/02/14 20:43:58 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_individually(t_data *data, t_list *a, t_list *b)
{
	int a_index;
	int	b_index;
	t_list **stack_a;
	t_list **stack_b;

	stack_a = data->a;
	stack_b = data->b;
	a_index = a->index;
	b_index	= b->index;
	while((*stack_a)->index != a_index)
	{
		if(a->direction == 0)
			rotate(data->a, "a");
		else
			reverse_rotate(data->a, "a");
	}
	while((*stack_b)->index != b_index)
	{
		if(b->direction == 0)
			rotate(data->b, "b");
		else
			reverse_rotate(data->b, "b");
	}
}
void	get_nodes_to_top(t_data *data, t_list *a, t_list *b)
{
	rotate_individually(data, a, b);
}
void	turk(t_data *data)
{
	t_list *cheapest;
	t_list	*max;

	push(data->a, data->b, "b");
	push(data->a, data->b, "b");
	while(!check_ordered_circular(*(data->a)))
	{
		set_attributes(data->a, data->b);
		cheapest = find_cheapest_node(*(data->a));
		get_nodes_to_top(data, cheapest, cheapest->target);
		push(data->a, data->b, "a");
	}
	max = find_biggest(*(data->b));
	ft_printf("max index: %d\n", max->index);
	ft_printf("b index: %d\n", data->b[0]->index);
	rotate(data->b, "b");
	ft_printf("max index: %d\n", max->index);
	ft_printf("b index: %d\n", data->b[0]->index);
	while((data->b[0]->index) != (max->index))
	{
		if(max->direction == 0)
			rotate(data->b, "b");
	}
	swap(data->b, "b");
	ft_printf("%d\n", check_ordered(*(data->b)));
}
