/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:02:32 by busseven          #+#    #+#             */
/*   Updated: 2025/02/15 15:23:55 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pick_cost(t_list *a, int rr, int rrr, int cost)
{
	a->rr = rr;
	a->rrr = rrr;
	return(cost);
}
int		set_costs(t_list *a, t_list *b)
{
	int	ind_cost;
	int rr_cost;
	int	rrr_cost;

	set_distances(a, b);
	ind_cost = calc_ind_cost(a, b);
	rr_cost = calc_rr_cost(a, b);
	rrr_cost = calc_rrr_cost(a, b);
	if((ind_cost <= rr_cost) && (ind_cost <= rrr_cost))
		return(pick_cost(a, 0, 0, ind_cost));
	else if((rrr_cost <= rr_cost) && (rrr_cost <= ind_cost))
		return(pick_cost(a, 0, 1, rrr_cost));
	else
		return(pick_cost(a, 1, 0, rr_cost));
}
int		count_targets(t_list *a, t_list *b)
{
	int	count;

	count = 0;
	while(b)
	{
		if((b->index) < (a->index))
			count++;
		b = b->next;
	}
	return(count);
}
int		count_targets2(t_list *a, t_list *b)
{
	int	count;

	count = 0;
	while(b)
	{
		if((b->index) > (a->index))
			count++;
		b = b->next;
	}
	return(count);
}
t_list	*set_target(t_list *a, t_list **b)
{
	int count;

	count = count_targets(a, *b);
	if(count == 0)
		a->target = find_biggest(*b);
	else
		a->target = find_biggest_lower_than(*b, a->index);
	return(a->target);
}
t_list	*find_smallest_higher_than(t_list *stack, int x)
{
	t_list *comp;
	t_list	*min = NULL;

	comp = stack;
	while(comp)
	{
		if((comp->index > x) && (min == NULL || (comp->index < min->index)))
			min = comp;
		else
			comp = comp->next;
	}
	return(min);
}
t_list	*set_target2(t_list *a, t_list **b)
{
	int count;

	count = count_targets2(a, *b);
	if(count == 0)
		a->target = find_smallest(*b);
	else
		a->target = find_smallest_higher_than(*b, a->index);
	return(a->target);
}
void	set_attributes(t_list **a, t_list **b)
{
	t_list *temp;

	temp = *a;
	while(*a)
	{
		(*a)->target = set_target(*a, b);
		(*a)->cost = set_costs(*a, *b);
		*a = (*a)->next;
	}
	*a = temp;
}
void	set_attributes2(t_list **a, t_list **b)
{
	t_list *temp;

	temp = *a;
	while(*a)
	{
		(*a)->target = set_target2(*a, b);
		(*a)->cost = set_costs(*a, *b);
		*a = (*a)->next;
	}
	*a = temp;
}