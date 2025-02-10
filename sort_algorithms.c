/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:18:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/10 11:12:26 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_list **s, char *name)
{
	swap(s, name);
}

void	three_sort(t_list **s, char *name)
{
	if(((*s)->index > (*s)->next->index) && ((*s)->index > (*s)->next->next->index))
		rotate(s, name);
	else if(((*s)->next->index > (*s)->index) && ((*s)->next->index > (*s)->next->next->index))
		reverse_rotate(s, name);
	if((*s)->index > (*s)->next->index)
			swap(s, name);
}

void	tiny_sort(t_list **a, char *name, int count)
{
	if(count == 2 && (*a)->index > (*a)->next->index)
		two_sort(a, name);
	else if(count == 3)
		three_sort(a, name);
}