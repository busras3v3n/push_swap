/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:48:03 by busseven          #+#    #+#             */
/*   Updated: 2025/02/12 14:17:07 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d_arr(char **arr)
{
	int	i;
	
	i = 0;
	while(arr[i])
		free(arr[i++]);
	if(arr)
		free(arr);
}

void	free_data_exit(t_data	*data)
{
	if(data->a)
		free(data->a);
	if(data->b)
		free(data->b);
	if(data->numbers)
		free_2d_arr(data->numbers);
	if(data)
		free(data);
	exit(1);
}
int	get_2d_length(char **arr)
{
	int	i;
	
	i = 0;
	while(arr[i])
		i++;
	return(i);
}