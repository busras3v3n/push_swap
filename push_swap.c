/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/11 17:59:47 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handling(char **argv)
{
	check_for_doubles(argv);
	check_for_invalid_char(argv);
	check_for_non_int(argv);
}

int main(int argc, char **argv)
{
	if(argc >= 2)
	{
		if(argc == 2)
			error_handling(ft_split(argv[1], ' '));
		else
			error_handling(argv);
	}
	else
		write(2, "Error\nno arguments\n", 19);
}
