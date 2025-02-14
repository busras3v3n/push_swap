/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:36 by busseven          #+#    #+#             */
/*   Updated: 2025/02/14 13:23:09 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk(t_data *data)
{
	t_list *cheapest;

	push(data->a, data->b, "b");
	push(data->a, data->b, "b");
	while(ft_lstsize(*(data->a)) > 3)
	{
		set_attributes(data->a, data->b);
		cheapest = find_cheapest_node(*(data->a));
		ft_printf("%d\n", cheapest->index);
		break;
	}
}