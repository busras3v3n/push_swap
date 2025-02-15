/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:36 by busseven          #+#    #+#             */
/*   Updated: 2025/02/15 14:51:32 by busseven         ###   ########.fr       */
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
int		check_ordered_circular(t_list *a)
{
	t_list *min;

	min = find_smallest(a);
	if(!check_ordered_linear(min))
		return(0);
	if((a->index != min->index) && (ft_lstlast(a)->index > a->index))
		return(0);
	if(!check_ordered_linear2(a, min->index))
		return(0);
	return(1);
}
void	turk(t_data *data)
{
	t_list *cheapest;

	push(data->a, data->b, "b");
	push(data->a, data->b, "b");
	while(*(data->a) && !check_ordered_circular(*(data->a)))
	{
		if(ft_lstsize(*(data->a)) < 2)
			break ;
		set_attributes(data->a, data->b);
		cheapest = find_cheapest_node(*(data->a));
		get_nodes_to_top(data, cheapest, cheapest->target);
		push(data->a, data->b, "b");
	}
}
