/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:36 by busseven          #+#    #+#             */
/*   Updated: 2025/02/13 12:50:38 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_targets(t_list *a, t_list *b)
{
	int	count;

	count = 0;
	while(b)
	{
		if(b->index < a->index)
			count++;
		b = b->next;
	}
	return(count);
}
int		find_biggest_arr(int *arr)
{
	int max;
	int i;
	
	max = 0;
	i = 0;
	while(arr[i])
	{
		if(arr[i] > max)
			max = arr[i];
		i++;
	}
	return(max);
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
void	set_costs(t_list **a, t_list **b)
{
	t_list *temp;

	temp = *a;
	while(*a)
	{
		(*a)->target = set_target(*a, b);
		*a = (*a)->next;
	}
	*a = temp;
}
void	turk(t_data *data)
{
	push(data->a, data->b, "b");
	push(data->a, data->b, "b");
	set_costs(data->a, data->b);
}