/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:21:06 by busseven          #+#    #+#             */
/*   Updated: 2025/02/14 20:43:32 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char *name)
{
	t_list *temp;
	t_list	*next_temp;

	if(ft_lstsize(*stack) > 1)
	{
    	temp = *stack;
		(*stack) = (*stack)->next;
		next_temp = (*stack)->next;
		(*stack)->next = temp;
		temp->next = next_temp;
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
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
	ft_printf("rr%s\n", name);
}
t_list	*previous_node(t_list **list, t_list *node)
{
	t_list *temp;
	t_list	*ret;

	temp = *list;
	while(*list)
	{
		if((*list)->next == node)
		{
			ret = *list;
			*list = temp;
			return(ret);
		}
		*list = (*list)->next;
	}
	ret = *list;
	*list = temp;
	return(NULL);
}
void	reverse_rotate(t_list **stack, char *name)
{
	t_list *last;

	last = ft_lstlast(*stack);
	while(last->position != 0)
	{
		ft_lstswap(last, previous_node(stack, last));
		last = previous_node(stack, last);
	}
	ft_printf("rr%s\n", name);
}