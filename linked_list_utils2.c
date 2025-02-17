/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:00 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 10:51:16 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_biggest(t_list *stack)
{
	t_list *comp;

	comp = stack;
	while (comp)
	{
		if (comp->index > stack->index)
			stack = comp;
		else
			comp = comp->next;
	}
	return (stack);
}
t_list	*find_smallest(t_list *stack)
{
	t_list *comp;

	comp = stack;
	while (comp)
	{
		if (comp->index < stack->index)
			stack = comp;
		else
			comp = comp->next;
	}
	return (stack);
}

t_list	*find_biggest_lower_than(t_list *stack, int x)
{
	t_list *comp;
	t_list	*biggest = NULL;

	comp = stack;
	while (comp)
	{
		if ((comp->index < x) && (biggest == NULL || (comp->index > biggest->index)))
			biggest = comp;
		else
			comp = comp->next;
	}
	return (biggest);
}

void	set_real_index(t_list *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		stack->position = i;
		stack = stack->next;
		i++;
	}
}
t_list	*previous_node(t_list **list, t_list *node)
{
	t_list *temp;
	t_list	*ret;

	temp = *list;
	while (*list)
	{
		if ((*list)->next == node)
		{
			ret = *list;
			*list = temp;
			return(ret);
		}
		*list = (*list)->next;
	}
	ret = *list;
	*list = temp;
	return (NULL);
}