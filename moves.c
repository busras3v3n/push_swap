/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:21:06 by busseven          #+#    #+#             */
/*   Updated: 2025/02/15 20:19:10 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char *name)
{
	t_list *temp;
	t_list	*next_temp;

	(void)name;
	if(ft_lstsize(*stack) > 1)
	{
    	temp = *stack;
		(*stack) = (*stack)->next;
		next_temp = (*stack)->next;
		(*stack)->next = temp;
		temp->next = next_temp;
	}
}
void	push(t_list **from, t_list **to, char *to_name)
{
	t_list	*b_new_head;

	if(ft_lstsize(*from) > 0)
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
	ft_printf("p%s\n", to_name);
}
void	rotate(t_list **stack, char *name)
{
	t_list *temp;

	(void)name;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
}
void	reverse_rotate(t_list **stack, char *name)
{
	t_list *last;
	t_list *prev;
	t_list	*sec;

	sec = *stack;
	last = ft_lstlast(*stack);
	prev = previous_node(stack, last);
	prev->next = NULL;
	*stack = last;
	last->next = sec;
	ft_printf()
}