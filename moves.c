/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:21:06 by busseven          #+#    #+#             */
/*   Updated: 2025/02/14 19:32:43 by busseven         ###   ########.fr       */
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
		temp = (*stack)->index;
		(*stack)->index= (*stack)->next->index;
		(*stack)->next->index = temp;
	}
	ft_printf("s%s\n", name);
}
void	push(t_list **from, t_list **to, char *to_name)
{
	t_list	*remove;
	t_list	*new;

	if(ft_lstsize(*from) > 0)
	{
		new = ft_lstnew((*from)->content);
		new->index = (*from)->index;
		ft_lstadd_front(to, new);
		remove = *from;
		*from = (*from)->next;
		free(remove);	
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

	temp = *stack;
	while(*stack && (*stack)->next)
	{
		ft_lstswap(*stack, (*stack)->next);
		*stack = (*stack)->next;
	}
	*stack = temp;
	ft_printf("rr%s\n", name);
}

void	reverse_rotate(t_list **stack, char *name)
{
	t_list *new;
	t_list *remove;
	
	if(ft_lstsize(*stack) > 1)
	{
		new = ft_lstnew(ft_lstlast(*stack)->content);
		new->index = ft_lstlast(*stack)->index;
		ft_lstadd_front(stack, new);
		remove = ft_lstlast(*stack);
		ft_beforelstlast(*stack)->next = NULL;
		free(remove);
	}
	ft_printf("rr%s\n", name);
}