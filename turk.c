/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:36 by busseven          #+#    #+#             */
/*   Updated: 2025/02/14 09:29:08 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		calc_ind_cost(t_list *a, t_list *b)
{
	int	a_cost;
	int	b_cost;

	if(a->direction == 0)
		a_cost = a->x;
	else
		a_cost = a->y + 1;
	if(b->direction == 0)
		b_cost = b->x;
	else
		b_cost = b->y + 1;
	return(a_cost + b_cost);
}
void	set_distances(t_list *a, t_list *b)
{
	a->x = a->position;
	a->y = a->size - a->position - 1;
	b->x = b->position;
	b->y = b->size - b->position - 1;	
}
void	set_directions(t_list *a, t_list *b)
{
	if(a->position <= a->size / 2)
		a->direction = 0;
	else
		a->direction = 1;
	if(b->position <= a->size / 2)
		b->direction = 0;
	else
		b->direction = 1;
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
int		set_costs(t_list *a, t_list *b)
{
	int	individual_cost;

	set_distances(a, b);
	set_directions(a, b);
	individual_cost = calc_ind_cost(a, b);
	return(individual_cost);
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
void	turk(t_data *data)
{
	push(data->a, data->b, "b");
	push(data->a, data->b, "b");
	set_attributes(data->a, data->b);
}