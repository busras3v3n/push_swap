/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/10 19:56:59 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(int real_index, t_list **a, t_list **b)
{
	int size;
	int i;
	
	(void)a;
	size = ft_lstsize(*b);
	i = (size / 2) - 1;
	while(i > 0)
	{
		if(real_index > size / 2)
			reverse_rotate(b, "b");
		else
			rotate(b, "b");
		i--;
	}
}
int		all_bigger_than_pivot(t_list *a, int pivot)
{
	while(a)
	{
		if(a->index < pivot)
			return(0);
		a = a->next;
	}
	return(1);
}
void	push_small_half_to_b(t_list **a, t_list **b)
{
	int pivot;

	pivot = (find_biggest(a) + find_smallest(a)) / 2;
	while(*a && (*a)->index != -1 && !all_bigger_than_pivot(*a, pivot))
	{
		if((*a)->index < pivot)
			push(a, b, "b");
		else
			rotate(a, "a");
	}
}
void	quick_sort(t_list **a, t_list **b)
{
	t_list *temp;

	temp = *b;
	while(ft_lstsize(*a) > 3)
		push_small_half_to_b(a, b);
	tiny_sort(a, "a", 3);
	set_real_index(b);
	push_to_a(2, a, b);
	while(*a)
	{
		ft_printf("a: %d : %d : %d\n", (*a)->content, (*a)->real_index, (*a)->index);
		*a = (*a)->next;
	}
	while(*b)
	{
		ft_printf("b: %d : %d : %d\n", (*b)->content, (*b)->real_index, (*b)->index);
		*b = (*b)->next;
	}
}
void	sort(t_list **a, t_list **b, int count)
{
	if(count == 2 || count == 3)
		tiny_sort(a, "a", count);
	else
		quick_sort(a, b);
}

int	find_smallest(t_list **stack)
{
	int min;
	t_list *temp;

	temp = *stack;
	min = (*stack)->index;
	while(*stack && (*stack)->index != -1)
	{
		if(min > (*stack)->index)
			min = (*stack)->index;
		*stack = (*stack)->next;
	}
	*stack = temp;
	return(min);
}
int	find_biggest(t_list **stack)
{
	int max;
	t_list *temp;

	temp = *stack;
	max = 0;
	while(*stack && (*stack)->index != -1)
	{
		if(max < (*stack)->index)
			max = (*stack)->index;
		*stack = (*stack)->next;
	}
	*stack = temp;
	return(max);
}

void	set_real_index(t_list **stack)
{
	int i;
	t_list *temp;

	i = 0;
	temp = *stack;
	while(*stack)
	{
		(*stack)->real_index = i;
		i++;
		*stack = (*stack)->next;
	}
	*stack = temp;
}
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
	t_list	**b;

	a = ft_calloc(1, sizeof(t_list));
	b = ft_calloc(1, sizeof(t_list));
	if(argc >= 2)
	{
		error_handling(argv);
		init_stacks(argv, a);
		sort(a, b, argc - 1);
	}
	else
		write(2, "Error\nno arguments\n", 19);
}
