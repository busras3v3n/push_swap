/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:23:56 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 17:24:31 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	both_swap_bonus(t_list **stack_a, t_list **stack_b)
{
	swap_bonus(stack_a);
	swap_bonus(stack_b);
}

void	both_rotate_bonus(t_list **stack_a, t_list **stack_b)
{
	rotate_bonus(stack_a);
	rotate_bonus(stack_b);
}

void	both_reverse_bonus(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_bonus(stack_a);
	reverse_rotate_bonus(stack_b);
}