/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:03:53 by busseven          #+#    #+#             */
/*   Updated: 2025/02/07 14:14:18 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list **a)
{
}
int		is_sign(char c)
{
	return(c == '-' || c == '+');
}

int		is_greater(int k, int l)
{
	return(k > l);
}
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL)
		return ;
	else
	{
		last = ft_lstlast(*lst);
		if (last == NULL)
		{
			*lst = new;
		}
		else
		{
			last->next = new;
		}
	}
}
t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->index = 0;
	new->next = NULL;
	return (new);
}
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		if (!lst->next)
			return (i);
		lst = lst->next;
	}
	return (i);
}
void	ft_lstswap(t_list *number1, t_list *number2)
{
	int temp;
	
	temp = number1->content;
	number1->content = number2->content;
	number2->content = temp;
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
