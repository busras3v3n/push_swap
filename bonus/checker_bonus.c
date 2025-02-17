/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:26:13 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 17:16:29 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_if_sorted(t_data *data)
{
	if(check_ordered_linear(*(data->a)) && !ft_lstsize(*(data->b)))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_data_exit(data, 0);
}
void	check_action(t_data *data, char *line)
{
	if(!ft_strncmp(line, "sa\n", ft_strlen(line)))
		swap_bonus(data->a);
	else if(!ft_strncmp(line, "sb\n", ft_strlen(line)))
		swap_bonus(data->b);
	else if(!ft_strncmp(line, "ss\n", ft_strlen(line)))
		both_swap_bonus(data->a, data->b);
	else if(!ft_strncmp(line, "ra\n", ft_strlen(line)))
		rotate_bonus(data->a);
	else if(!ft_strncmp(line, "rb\n", ft_strlen(line)))
		rotate_bonus(data->b);
	else if(!ft_strncmp(line, "rr\n", ft_strlen(line)))
		both_rotate_bonus(data->b, data->a);
	else if(!ft_strncmp(line, "rra\n", ft_strlen(line)))
		reverse_rotate_bonus(data->a);
	else if(!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		reverse_rotate_bonus(data->b);
	else if(!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		both_reverse_bonus(data->b, data->a);
	else if(!ft_strncmp(line, "pa\n", ft_strlen(line)))
		push_bonus(data->b, data->a);
	else if(!ft_strncmp(line, "pb\n", ft_strlen(line)))
		push_bonus(data->a, data->b);
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

char	*add_chars(char *str, char a)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_calloc(ft_strlen(str) + 2, sizeof(char));
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = a;
	temp[i + 1] = '\0';
	free(str);
	return (temp);
}
int	check_line_validity(t_data *data, char *line)
{
	char	**valid_moves;
	int		i;

	valid_moves = ft_split("sa sb ss ra rb rr rra rrb rrr pa pb", ' ');
	while(valid_moves[i])
	{
		valid_moves[i] = add_chars(valid_moves[i], '\n');
		i++;
	}
	i = 0;
	while(valid_moves[i])
	{
		if(!ft_strncmp(valid_moves[i], line, ft_strlen(line)))
		{
			free_2d_arr(valid_moves);
			return(1);
		}
		i++;
	}
	free_2d_arr(valid_moves);
	return(0);
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
		while(1)
		{
			line = get_next_line2(0, 1);
			if(!line)
				break ;
			if(!check_line_validity(data, line))
			{
				write(2, "Error\n", 6);
				free(line);
				get_next_line2(0, 0);
				free_data_exit(data, 1);
			}
			check_action(data, line);
			free(line);
		}
		check_if_sorted(data);
	}
}
