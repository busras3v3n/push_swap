/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:13:40 by busseven          #+#    #+#             */
/*   Updated: 2025/02/07 12:55:32 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int temp;

	if(ft_lstsize(*stack) > 1)
	{
    	temp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = temp;
	}
}
void	push(t_list **from, t_list **to)
{
	t_list	*remove;

	if(ft_lstsize(*from) > 0)
	{
		ft_lstadd_front(to, ft_lstnew((*from)->content));
		remove = *from;
		*from = (*from)->next;
		free(remove);	
	}
}
void	rotate(t_list **stack)
{
	t_list	*remove;

	if(ft_lstsize(*stack) > 1)
	{
		ft_lstadd_back(stack, ft_lstnew((*stack)->content));
		remove = *stack;
		*stack = (*stack)->next;
		free(remove);	
	}
}

void	reverse_rotate(t_list **stack)
{
	if(ft_lstsize(*stack) > 1)
	{
		ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
		free(ft_lstlast(*stack));
	}
}
void	both_swap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
void	both_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
void	both_reverse(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
