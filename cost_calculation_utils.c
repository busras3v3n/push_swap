/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:01:10 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 10:49:48 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		calc_ind_cost(t_list *a, t_list *b)
{
	int	a_cost;
	int	b_cost;

	if (a->direction == 0)
		a_cost = a->x;
	else
		a_cost = a->y + 1;
	if (b->direction == 0)
		b_cost = b->x;
	else
		b_cost = b->y + 1;
	return (a_cost + b_cost);
}
int		calc_rr_cost(t_list *a, t_list *b)
{
	if ((a->x) >= (b->x))
		return (a->x);
	else
		return (b->x);
}
int		calc_rrr_cost(t_list *a, t_list *b)
{
	if ((a->y) >= (b->y))
		return (a->y + 1);
	else
		return (b->y + 1);
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
	if ((a->position) <= (a->size / 2))
		a->direction = 0;
	else
		a->direction = 1;
	if ((b->position) <= (b->size / 2))
		b->direction = 0;
	else
		b->direction = 1;
}