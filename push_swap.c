/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/06 17:10:57 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(char **argv, t_list **a)
{
	int i;
	t_list	*new;

	i = 1;
	while(argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(a, new);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_list	**a;

	a = ft_calloc(1, sizeof(t_list));
	if(argc >= 2)
	{
		check_for_doubles(argv);
		check_for_invalid_char(argv);
		check_for_non_int(argv);
		init_stacks(argv, a);
		while(*a)
		{
			ft_printf("%d", (*a)->content);
			*a = (*a)->next;
		}
	}
	else
		ft_printf("Error\nno arguments\n");
}
