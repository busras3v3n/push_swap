/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:36 by busseven          #+#    #+#             */
/*   Updated: 2025/02/14 13:09:29 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_together(t_list *a, t_list *b, t_list **stack_a, t_list **stack_b)
{
	int amount;
	
	if((a->y) >= (b->y))
	{
		amount = (a->y) - (b->y);
		while(amount > 0)
		{
			both_reverse(stack_a, stack_b);
			amount--;
		}
		amount = b->y + 1;
	}
	else
	{
		amount = (b->y) - (a->y);
		while(amount > 0)
		{
			both_reverse(stack_a, stack_b);
			amount--;
		}
		amount = a->y + 1;
	}
	while(amount > 0)
	{
		both_reverse(stack_a, stack_b);
		amount--;
	}
}

void	rotate_together(t_list *a, t_list *b, t_list **stack_a, t_list **stack_b)
{
	int amount;
	
	if((a->x) >= (b->x))
	{
		amount = (a->x) - (b->x);
		while(amount > 0)
		{
			rotate(stack_a, "a");
			amount--;
		}
		amount = b->x;
	}
	else
	{
		amount = (b->x) - (a->x);
		while(amount > 0)
		{
			rotate(stack_b, "b");
			amount--;
		}
		amount = a->x;
	}
	while(amount > 0)
	{
		both_rotate(stack_a, stack_b);
		amount--;
	}
}
void	rotate_individually(t_list *a, t_list *b, t_list **stack_a, t_list **stack_b)
{
	int	a_index;
	int	b_index;

	a_index = a->index;
	b_index = b->index;
	while((*stack_a)->index != a_index)
	{
		if(a->direction == 0)
			rotate(stack_a, "a");
		else
			reverse_rotate(stack_a, "a");
	}
	while((*stack_b)->index != b_index)
	{
		if(b->direction == 0)
			rotate(stack_b, "b");
		else
			reverse_rotate(stack_b, "b");
	}
}
void	get_nodes_on_top(t_list *a, t_list *b, t_list **stack_a, t_list **stack_b)
{
	if(a->rr == 0 && a->rrr == 0)
		rotate_individually(a, b, stack_a, stack_b);
	else if(a->rr == 1)
		rotate_together(a, b, stack_a, stack_b);
	else if(a->rrr == 1)
		reverse_rotate_together(a, b, stack_a, stack_b);
}
void	turk(t_data *data)
{
	t_list *cheapest;

	push(data->a, data->b, "b");
	push(data->a, data->b, "b");
	while(ft_lstsize(*(data->a)) > 3)
	{
		set_attributes(data->a, data->b);
		cheapest = find_cheapest_node(*(data->a));
		push(data->a, data->b, "b");
		cheapest = find_cheapest_node(*(data->a));
		ft_printf("%d\n", cheapest->index);
		break;
	}
}