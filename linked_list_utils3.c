/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:59:18 by busseven          #+#    #+#             */
/*   Updated: 2025/02/14 10:06:55 by busseven         ###   ########.fr       */
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