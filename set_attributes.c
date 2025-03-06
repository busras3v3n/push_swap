/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:02:32 by busseven          #+#    #+#             */
/*   Updated: 2025/03/06 12:59:27 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pick_cost(t_list *a, int rr, int rrr, int cost)
{
	a->rr = rr;
	a->rrr = rrr;
	return (cost);
}

int	set_costs(t_list *a, t_list *b)
{
	int	ind_cost;
	int	rr_cost;
	int	rrr_cost;

	set_distances(a, b);
	ind_cost = calc_ind_cost(a, b);
	rr_cost = calc_rr_cost(a, b);
	rrr_cost = calc_rrr_cost(a, b);
	if ((ind_cost <= rr_cost) && (ind_cost <= rrr_cost))
		return (pick_cost(a, 0, 0, ind_cost));
	else if ((rrr_cost <= rr_cost) && (rrr_cost <= ind_cost))
		return (pick_cost(a, 0, 1, rrr_cost));
	else
		return (pick_cost(a, 1, 0, rr_cost));
}

int	count_smaller_a(t_list *a, t_list *b)
{
	int	count;

	count = 0;
	while (b)
	{
		if ((b->index) < (a->index))
			count++;
		b = b->next;
	}
	return (count);
}

t_list	*set_target_a(t_list *a, t_list **b)
{
	int	count;

	count = count_smaller_a(a, *b);
	if (count == 0)
		a->target = find_biggest(*b);
	else
		a->target = find_biggest_lower_than(*b, a->index);
	return (a->target);
}

void	set_attributes_a(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	set_real_index(*a);
	set_real_index(*b);
	while (*a)
	{
		(*a)->target = set_target_a(*a, b);
		(*a)->cost = set_costs(*a, (*a)->target);
		*a = (*a)->next;
	}
	*a = temp;
}
