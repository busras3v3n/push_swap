/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:58:13 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 12:37:30 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_individually(t_data *data, t_list *a, t_list *b)
{
	int		a_index;
	int		b_index;
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = data->a;
	stack_b = data->b;
	a_index = a->index;
	b_index = b->index;
	while (((*stack_a)->index) != a_index)
	{
		if (a->direction == 0)
			rotate(data->a, "a");
		else
			reverse_rotate(data->a, "a");
	}
	while (((*stack_b)->index) != b_index)
	{
		if (b->direction == 0)
			rotate(data->b, "b");
		else
			reverse_rotate(data->b, "b");
	}
}

void	rotate_together(t_data *data, t_list *a, t_list *b)
{
	while (*(data->a) != a && *(data->b) != b)
		both_rotate(data->a, data->b);
	while (*(data->a) != a)
		rotate(data->a, "a");
	while (*(data->b) != b)
		rotate(data->b, "b");
}

void	reverse_rotate_together(t_data *data, t_list *a, t_list *b)
{
	while (*(data->a) != a && *(data->b) != b)
		both_reverse(data->a, data->b);
	while (*(data->a) != a)
		reverse_rotate(data->a, "a");
	while (*(data->b) != b)
		reverse_rotate(data->b, "b");
}

int	check_ordered_circular(t_list *a)
{
	t_list	*min;

	min = find_smallest(a);
	if (!check_ordered_linear(min))
		return (0);
	if ((a->index != min->index) && (ft_lstlast(a)->index > a->index))
		return (0);
	if (!check_ordered_linear2(a, min->index))
		return (0);
	return (1);
}
