/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:36 by busseven          #+#    #+#             */
/*   Updated: 2025/02/15 20:18:39 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_individually(t_data *data, t_list *a, t_list *b)
{
	int a_index;
	int	b_index;
	t_list **stack_a;
	t_list **stack_b;

	stack_a = data->a;
	stack_b = data->b;
	a_index = a->index;
	b_index	= b->index;
	ft_printf("ri!\n");
	while(((*stack_a)->index) != a_index)
	{
		if(a->direction == 0)
			rotate(data->a, "a");
		else
			reverse_rotate(data->a, "a");
	}
	while(((*stack_b)->index) != b_index)
	{
		if(b->direction == 0)
			rotate(data->b, "b");
		else
			reverse_rotate(data->b, "b");
	}
}
void	rotate_together(t_data *data, t_list *a, t_list *b)
{
	while(*(data->a) != a && *(data->b) != b)
		both_rotate(data->a, data->b);
	while(*(data->a) != a)
		rotate(data->a, "a");
	while(*(data->b) != b)
		rotate(data->b, "b");
}
void	reverse_rotate_together(t_data *data, t_list *a, t_list *b)
{
	while(*(data->a) != a && *(data->b) != b)
		both_reverse(data->a, data->b);
	while(*(data->a) != a)
		reverse_rotate(data->a, "a");
	while(*(data->b) != b)
		reverse_rotate(data->b, "b");
}
void	get_nodes_to_top(t_data *data, t_list *a, t_list *b)
{
	ft_printf("searching for the best option\n");
	if(a->rr == 0 && a->rrr == 0)
		rotate_individually(data, a, b);
	else if(a->rr == 1)
		rotate_together(data, a, b);
	else if(a->rrr == 1)
		reverse_rotate_together(data, a, b);
}
void	get_nodes_to_top2(t_data *data, t_list *b, t_list *a)
{
	if(b->rr == 0 && b->rrr == 0)
		rotate_individually(data, a, b);
	else if(b->rr == 1)
		rotate_together(data, a, b);
	else if(b->rrr == 1)
		reverse_rotate_together(data, a, b);
}
int		check_ordered_circular(t_list *a)
{
	t_list *min;

	min = find_smallest(a);
	if(!check_ordered_linear(min))
		return(0);
	if((a->index != min->index) && (ft_lstlast(a)->index > a->index))
		return(0);
	if(!check_ordered_linear2(a, min->index))
		return(0);
	return(1);
}
void	rotate_sorted_lists(t_data *data, t_list **a, t_list **b)
{
	t_list	*max_b;
	t_list	*min_a;

	max_b = find_biggest(*b);
	min_a = find_smallest(*a);
	set_costs(min_a, max_b);
	get_nodes_to_top(data, min_a, max_b);
}
void	turk(t_data *data)
{
	t_list	*cheapest;
	
	push(data->a, data->b, "b");
	push(data->a, data->b, "b");
	while(*(data->a))
	{
		set_attributes(data->a, data->b);
		cheapest = find_cheapest_node(*(data->a));
		get_nodes_to_top(data, cheapest, cheapest->target);
		ft_printf("%d, target: %d, rr: %d, rrr: %d, cost: %d\n", cheapest->content, cheapest->target->content, cheapest->rr, cheapest->rrr, cheapest->cost);
		push(data->a, data->b, "b");
	}
}
