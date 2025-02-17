/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:53:56 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 11:55:57 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_smallest_higher_than(t_list *stack, int x)
{
	t_list	*comp;
	t_list	*min;

	min = NULL;
	comp = stack;
	while (comp)
	{
		if ((comp->index > x) && (min == NULL || (comp->index < min->index)))
			min = comp;
		else
			comp = comp->next;
	}
	return (min);
}

int	count_targets2(t_list *a, t_list *b)
{
	int	count;

	count = 0;
	while (b)
	{
		if ((b->index) > (a->index))
			count++;
		b = b->next;
	}
	return (count);
}

t_list	*set_target2(t_list *a, t_list **b)
{
	int	count;

	count = count_targets2(a, *b);
	if (count == 0)
		a->target = find_smallest(*b);
	else
		a->target = find_smallest_higher_than(*b, a->index);
	return (a->target);
}

void	set_attributes2(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	while (*a)
	{
		(*a)->target = set_target2(*a, b);
		(*a)->cost = set_costs(*a, *b);
		*a = (*a)->next;
	}
	*a = temp;
}
