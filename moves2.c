/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:04:46 by busseven          #+#    #+#             */
/*   Updated: 2025/02/12 15:05:02 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_swap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, "a");
	swap(stack_b, "b");
	ft_printf("ss\n");
}
void	both_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, "a");
	rotate(stack_b, "b");
	ft_printf("rr\n");
}
void	both_reverse(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, "a");
	reverse_rotate(stack_b, "b");
	ft_printf("rrr\n");
}