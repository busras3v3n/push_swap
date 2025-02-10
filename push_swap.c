/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/10 11:40:33 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_index(int content, t_list *a)
{
	int i;

	i = 0;
	while(a)
	{
		if(content > a->content)
			i++;
		else if(content < a->content)
			(a->index)++;
		a = a->next;
	}
	return(i);
}
void	init_stacks(char **argv, t_list **a)
{
	int i;
	int content;
	t_list	*new;

	i = 1;
	while(argv[i])
	{
		content = ft_atoi(argv[i]);
		new = ft_lstnew(content);
		new->index = set_index(content, *a);
		new->real_index = i - 1;
		ft_lstadd_back(a, new);
		i++;
	}
}
void	error_handling(char **argv)
{
	check_for_doubles(argv);
	check_for_invalid_char(argv);
	check_for_non_int(argv);
}

int main(int argc, char **argv)
{
	t_list	**a;

	a = ft_calloc(1, sizeof(t_list));
	if(argc >= 2)
	{
		error_handling(argv);
		init_stacks(argv, a);
		while(*a)
		{
			ft_printf("%d : %d : %d\n", (*a)->content, (*a)->real_index, (*a)->index);
			*a = (*a)->next;
		}
	}
	else
		write(2, "Error\nno arguments\n", 19);
}
