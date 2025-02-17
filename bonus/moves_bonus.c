/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:46:25 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 17:39:40 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	swap_bonus(t_list **stack)
{
	t_list	*temp;
	t_list	*next_temp;

	if (ft_lstsize(*stack) > 1)
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		next_temp = (*stack)->next;
		(*stack)->next = temp;
		temp->next = next_temp;
	}
}

void	push_bonus(t_list **from, t_list **to)
{
	t_list	*b_new_head;

	if (ft_lstsize(*from) > 0)
	{
		b_new_head = *from;
		*from = (*from)->next;
		b_new_head->next = *to;
		*to = b_new_head;
	}
	set_real_index(*from);
	set_real_index(*to);
	set_lstsizes(from);
	set_lstsizes(to);
	set_directions_list(*from);
	set_directions_list(*to);
}

void	rotate_bonus(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
}

void	reverse_rotate_bonus(t_list **stack)
{
	t_list	*last;
	t_list	*prev;
	t_list	*sec;

	sec = *stack;
	last = ft_lstlast(*stack);
	prev = previous_node(stack, last);
	prev->next = NULL;
	*stack = last;
	last->next = sec;
}
