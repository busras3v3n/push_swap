/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:58:13 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 12:00:44 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_ordered_circular(t_list *a)
{
	t_list *min;

	min = find_smallest(a);
	if (!check_ordered_linear(min))
		return(0);
	if ((a->index != min->index) && (ft_lstlast(a)->index > a->index))
		return(0);
	if (!check_ordered_linear2(a, min->index))
		return(0);
	return (1);
}
