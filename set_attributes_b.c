/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:53:56 by busseven          #+#    #+#             */
/*   Updated: 2025/03/06 13:09:36 by busseven         ###   ########.fr       */
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

int	count_bigger_b(t_list *b, t_list *a)
{
	int	count;

	count = 0;
	while (a)
	{
		if ((a->index) > (b->index))
			count++;
		a = a->next;
	}
	return (count);
}

t_list	*set_target_b(t_list *b, t_list **a)
{
	int	count;

	count = count_bigger_b(b, *a);
	if (count == 0)
		b->target = find_smallest(*a);
	else
		b->target = find_smallest_higher_than(*a, b->index);
	return (b->target);
}

void	set_attributes_b(t_list **b, t_list **a)
{
	t_list	*temp;

	temp = *b;
	while (*b)
	{
		(*b)->target = set_target_b(*b, a);
		(*b)->cost = set_costs(*b, *a);
		*b = (*b)->next;
	}
	*b = temp;
}
