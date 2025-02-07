/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:05:23 by busseven          #+#    #+#             */
/*   Updated: 2025/02/07 14:11:28 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
