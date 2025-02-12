/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:36 by busseven          #+#    #+#             */
/*   Updated: 2025/02/12 17:59:03 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_targets(t_list *a, t_list **b)
{
	t_list *temp;
	int count;

	count = 0;
	temp = *b;
	while(*b)
	{
		if((*b)->index < a->index)
			count++;
		(*b) = (*b)->next;
	}
	*b = temp;
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
void	set_target(t_list *a, t_list **b)
{
	t_list *temp;
	int i;
	int *potential_targets;
	int count;

	temp = *b;
	i = 0;
	count = count_targets(a, b);
	if(count == 0)
	{
		potential_targets = NULL;
		a->target = find_biggest(b);
	}
	else
	{
		potential_targets = ft_calloc(count, sizeof(int));
		while(*b)
		{
			if((*b)->index < a->index)
				potential_targets[i] = (*b)->index;
			(*b) = (*b)->next;
			i++;
		}
		*b = temp;
		a->target = find_biggest_arr(potential_targets);
	}
	free(potential_targets);
}
void	set_costs(t_list **a, t_list **b)
{
	t_list *temp;

	temp = *a;
	while(*a)
	{
		set_target(*a, b);
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