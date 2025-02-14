/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:00 by busseven          #+#    #+#             */
/*   Updated: 2025/02/14 13:34:21 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_biggest(t_list *stack)
{
	t_list *comp;

	comp = stack;
	while(comp)
	{
		if(comp->index > stack->index)
			stack = comp;
		else
			comp = comp->next;
	}
	return(stack);
}
t_list	*find_biggest_lower_than(t_list *stack, int x)
{
	t_list *comp;
	t_list	*biggest = NULL;

	comp = stack;
	while(comp)
	{
		if((comp->index < x) && (biggest == NULL || (comp->index > biggest->index)))
			biggest = comp;
		else
			comp = comp->next;
	}
	return(biggest);
}

void	set_real_index(t_list *stack)
{
	int i;

	i = 0;
	while(stack)
	{
		stack->position = i;
		i++;
		stack = stack->next;
	}
}

void	ft_lstswap(t_list *number1, t_list *number2)
{
	int temp;
	
	temp = number1->content;
	number1->content = number2->content;
	number2->content = temp;
}
t_list	*ft_beforelstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}