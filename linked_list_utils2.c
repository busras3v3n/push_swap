/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:00 by busseven          #+#    #+#             */
/*   Updated: 2025/02/12 15:03:39 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_real_index(t_list **stack)
{
	int i;
	t_list *temp;

	i = 0;
	temp = *stack;
	while(*stack)
	{
		(*stack)->position = i;
		i++;
		*stack = (*stack)->next;
	}
	*stack = temp;
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