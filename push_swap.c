/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/12 15:01:17 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number_count(char **argv)
{
	int count;
	int	i;
	char **temp;

	count = 0;
	i = 1;
	while(argv[i])
	{
		temp = ft_split(argv[i], ' ');
		count += get_2d_length(temp);
		free_2d_arr(temp);
		i++;
	}
	return(count);
}
void	init_data_numbers(char **argv, t_data *data)
{
	char	**temp;
	int		n;
	int		i;
	int		k;

	i = 1;
	n = 0;
	data->numbers = ft_calloc(check_number_count(argv) + 1, sizeof(char *));
	while(argv[i])
	{
		k = 0;
		temp = ft_split(argv[i], ' ');
		while(temp[k])
		{
			data->numbers[n] = temp[k];
			n++;
			k++;
		}
		free(temp);
		i++;
	}	
}
void	check_arguments(char **numbers, t_data *data)
{
	check_for_invalid_char(numbers, data);
	check_for_non_int(numbers, data);
	check_for_doubles(numbers, data);
}
int		set_index(int content, t_list *a)
{
	int i;

	i = 0;
	while(a)
	{
		if(content > a->content)
			i++;
		else if(content < a->content)
			(a->index)++;
		a = a->next;
	}
	return(i);
}

void	put_nodes_in_a(t_list **a, char **numbers)
{
	t_list *new;
	int	i;

	i = 0;
	while(numbers[i])
	{
		new = ft_lstnew(ft_atoi(numbers[i]));
		new->index = set_index(new->content, *a);
		new->target = -1;
		new->cost = -1;
		new->position = -1;
		new->direction = -1;
		new->is_first = -1;
		ft_lstadd_back(a, new);
		i++;
	}
}
void	init_data(t_data *data, char **argv)
{
	init_data_numbers(argv, data);
	check_arguments(data->numbers, data);
	data->a = ft_calloc(1, sizeof(t_list **));
	data->b = ft_calloc(1, sizeof(t_list **));
	put_nodes_in_a(data->a, data->numbers);
}
int main(int argc, char **argv)
{
	t_data *data;
	int i;
	i = 0;

	data = ft_calloc(1, sizeof(t_data));
	if(argc >= 2)
	{
		init_data(data, argv);
		while(data->numbers[i])
		{
			ft_printf("%s", data->numbers[i]);
			i++;
		}
	}
	else
		write(2, "Error\nno arguments\n", 19);
}