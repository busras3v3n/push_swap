/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:59:18 by busseven          #+#    #+#             */
/*   Updated: 2025/02/15 13:20:01 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_ordered_linear(t_list *a)
{
	while(a && a->next)
	{
		if((a->index) > (a->next->index))
			return (0);
		a = a->next;
	}
	return (1);
}
int		check_ordered_circular(t_list *a)
{
	t_list *min;
	t_list *hold;
	t_list	*comp;

	min = find_smallest(a);
	comp = min->next;
	while(comp && comp->next)
	{
		hold = comp->next;
		while(hold != min)
		{
			if(comp->index > hold->index)
				return(0);
			if(!hold->next)
				hold = a;
			else
				hold = hold->next;
		}
		comp = comp->next;
	}
	if(comp->index > a->index)
		return(0);
	comp = a;
	while(comp && (comp != min))
	{
		if((comp->index) < (comp->next->index))
			return(0);
		comp = comp->next;
	}
	return(1);
}
int		check_ordered(t_list *a)
{
	t_list *start;
	t_list	*min;

	min = find_smallest(a);
	start = min->next;
	while((start) && (start->index != min->index))
	{
		if(!start->next)
		{
			if(start->index < a->index)
				return (0);
			start = a;
		}
		else
		{
			if(start->index < start->next->index)
				return (0);
			start = start->next;
		}
	}
	return(1);
}
void	set_lstsizes(t_list **stack)
{
	t_list	*start;

	start = *stack;
	while(*stack)
	{
		(*stack)->size = ft_lstsize(start);
		*stack = (*stack)->next;
	}
	*stack = start;
}
t_list	*find_cheapest_node(t_list *stack)
{
	t_list *comp;

	comp = stack;
	while(comp)
	{
		if((comp->cost) < (stack->cost))
			stack = comp;
		else
			comp = comp->next;
	}
	return(stack);
}
void	set_directions_list(t_list *a)
{
	while(a)
	{
		if((a->position) <= (a->size / 2))
			a->direction = 0;
		else
			a->direction = 1;
		a = a->next;
	}
}