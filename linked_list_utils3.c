/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:59:18 by busseven          #+#    #+#             */
/*   Updated: 2025/03/03 18:12:22 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ordered_linear(t_list *a)
{
	while (a && a->next)
	{
		if ((a->index) > (a->next->index))
			return (0);
		a = a->next;
	}
	return (1);
}

int	check_ordered_linear_until(t_list *a, int til)
{
	while (a && a->next && (a->next->index != til))
	{
		if ((a->index) > (a->next->index))
			return (0);
		a = a->next;
	}
	return (1);
}

void	set_lstsizes(t_list **stack)
{
	t_list	*start;

	start = *stack;
	while (*stack)
	{
		(*stack)->size = ft_lstsize(start);
		*stack = (*stack)->next;
	}
	*stack = start;
}

t_list	*find_cheapest_node(t_list *stack)
{
	t_list	*comp;

	comp = stack;
	while (comp)
	{
		if ((comp->cost) < (stack->cost))
			stack = comp;
		else
			comp = comp->next;
	}
	return (stack);
}

void	set_directions_list(t_list *a)
{
	while (a)
	{
		if ((a->position) <= (a->size / 2))
			a->direction = 0;
		else
			a->direction = 1;
		a = a->next;
	}
}
