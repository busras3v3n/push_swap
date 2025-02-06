/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/06 16:17:34 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sign(char c)
{
	return(c == '-' || c == '+');
}
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
void	check_for_doubles(char **argv)
{
	int i;
	int	n;

	i = 1;
	while(argv[i])
	{
		n = 1;
		while(argv[n])
		{
			if(i != n && ft_atoi(argv[i]) == ft_atoi(argv[n]))
			{
				ft_printf("doubles are forbidden\n");
				exit(1);
			}
			n++;		
		}
		i++;
	}
}
void	check_for_invalid_char(char **argv)
{
	int i;
	int n;

	i = 1;
	while(argv[i])
	{
		n = 0;
		while(argv[i][n])
		{
			if(is_sign(argv[i][n]) && n == 0)
				;
			else if(!ft_isdigit(argv[i][n]))
			{
				ft_printf("invalid character\n");
			}
			
			n++;
		}
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
		check_if_integer(argv);
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
