/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:05:23 by busseven          #+#    #+#             */
/*   Updated: 2025/02/08 12:18:53 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	decrease_indexes(t_list *s)
{
	while(s)
	{
		if(s->index != -1)
			s->index--;
		s = s->next;
	}
}

int		is_sorted(stack **a)
{
	while(*a && (*a)->next)
	{
		if(*a > (*a)->next)
			return(0);
		*a = (*a)->next;
	}
	return(1);
}
int		is_sorted_reverse(stack **a)
{
	while(*a && (*a)->next)
	{
		if(*a < (*a)->next)
			return(0);
		*a = (*a)->next;
	}
	return(1);
} 
