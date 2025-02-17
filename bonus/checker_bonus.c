/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:26:13 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 17:37:24 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_if_sorted(t_data *data)
{
	if (check_ordered_linear(*(data->a)) && !ft_lstsize(*(data->b)))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_data_exit(data, 0);
}

void	init_data_bonus(t_data *data, char **argv)
{
	init_data_numbers(argv, data);
	check_arguments(data->numbers, data);
	data->a = ft_calloc(1, sizeof(t_list **));
	data->b = ft_calloc(1, sizeof(t_list **));
	put_nodes_in_a(data->a, data->numbers);
	set_real_index(data->a[0]);
	set_real_index(data->b[0]);
	set_lstsizes(data->a);
	set_directions_list(*(data->a));
}

int	check_line_validity(t_data *data, char *line)
{
	char	**valid_moves;
	int		i;

	valid_moves = ft_split("sa sb ss ra rb rr rra rrb rrr pa pb", ' ');
	while (valid_moves[i])
	{
		valid_moves[i] = add_chars(valid_moves[i], '\n');
		i++;
	}
	i = 0;
	while (valid_moves[i])
	{
		if (!ft_strncmp(valid_moves[i], line, ft_strlen(line)))
		{
			free_2d_arr(valid_moves);
			return (1);
		}
		i++;
	}
	free_2d_arr(valid_moves);
	return (0);
}
void	read_line(t_data *data)
{
	while (1)
	{
		line = get_next_line2(0, 1);
		if (!line)
			break ;
		if (!check_line_validity(data, line))
		{
			write(2, "Error\n", 6);
			free(line);
			get_next_line2(0, 0);
			free_data_exit(data, 1);
		}
		check_action(data, line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*line;
	t_list	*temp_a;
	t_list	*temp_b;

	data = ft_calloc(1, sizeof(t_data));
	if (argc >= 2)
	{
		init_data_bonus(data, argv);
		read_line(data);
		check_if_sorted(data);
	}
}
