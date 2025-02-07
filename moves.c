/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:13:40 by busseven          #+#    #+#             */
/*   Updated: 2025/02/07 13:23:13 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char *name)
{
	int temp;

	if(ft_lstsize(*stack) > 1)
	{
    	temp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = temp;
	}
	ft_printf("s%s\n", name);
}
void	push(t_list **from, t_list **to, char *to_name)
{
	t_list	*remove;

	if(ft_lstsize(*from) > 0)
	{
		ft_lstadd_front(to, ft_lstnew((*from)->content));
		remove = *from;
		*from = (*from)->next;
		free(remove);	
	}
	ft_printf("p%s\n", to_name);
}
void	rotate(t_list **stack, char *name)
{
	t_list	*remove;

	if(ft_lstsize(*stack) > 1)
	{
		ft_lstadd_back(stack, ft_lstnew((*stack)->content));
		remove = *stack;
		*stack = (*stack)->next;
		free(remove);	
	}
	ft_printf("r%s\n", name);
}

void	reverse_rotate(t_list **stack, char *name)
{
	if(ft_lstsize(*stack) > 1)
	{
		ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
		free(ft_lstlast(*stack));
	}
	ft_printf("rr%s\n", name);
}
void	both_swap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
void	both_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
void	both_reverse(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
