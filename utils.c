/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:48:03 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 12:41:09 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	free(lst);
}

void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	if (arr)
		free(arr);
}

void	free_data_exit(t_data	*data, int ext)
{
	if (data->a)
		free_list(data->a);
	if (data->b)
		free_list(data->b);
	if (data->numbers)
		free_2d_arr(data->numbers);
	if (data)
		free(data);
	exit(ext);
}

int	get_2d_length(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
