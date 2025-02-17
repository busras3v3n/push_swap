/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:04:46 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 10:27:21 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rotate_no_print(t_list **stack)
{
	t_list *temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
}
void	reverse_rotate_no_print(t_list **stack)
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
}

void	both_swap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, "a");
	swap(stack_b, "b");
	ft_printf("ss\n");
}
void	both_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate_no_print(stack_a);
	rotate_no_print(stack_b);
	ft_printf("rr\n");
}
void	both_reverse(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_no_print(stack_a);
	reverse_rotate_no_print(stack_b);
	ft_printf("rrr\n");
}