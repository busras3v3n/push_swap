/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:59:18 by busseven          #+#    #+#             */
/*   Updated: 2025/02/14 13:07:28 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
t_list	*find_cheapest_node(t_list *stack)
{
	t_list *comp;

	comp = stack;
	while(comp)
	{
		if((comp->cost) < (stack->cost))
			stack = comp;
		else
			comp = comp->next;
	}
	return(stack);
}