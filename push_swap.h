/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:53:37 by busseven          #+#    #+#             */
/*   Updated: 2025/03/03 18:12:11 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*target;
	int				x;
	int				y;
	int				rr;
	int				rrr;
	int				cost;
	int				size;
	int				position;
	int				direction;
	int				is_first;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_list	**a;
	t_list	**b;
	char	**numbers;
}	t_data;

void	check_for_invalid_char(char **ints, t_data *data);
void	check_for_non_int(char **ints, t_data *data);
void	check_for_doubles(char **ints, t_data *data);
int		get_2d_length(char **arr);
void	free_data_exit(t_data	*data, int exit);
void	free_2d_arr(char **arr);
t_list	*ft_beforelstlast(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_lstswap(t_list *number1, t_list *number2);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	set_real_index(t_list *stack);
void	swap(t_list **stack, char *name);
void	push(t_list **from, t_list **to, char *to_name);
void	rotate(t_list **stack, char *name);
void	reverse_rotate(t_list **stack, char *name);
void	put_nodes_in_a(t_list **a, char **numbers);
void	init_data_numbers(char **argv, t_data *data);
void	check_arguments(char **numbers, t_data *data);
t_list	*ft_lstnew(int content);
t_list	*find_biggest(t_list *stack);
void	turk(t_data *data);
t_list	*find_biggest_lower_than(t_list *stack, int x);
void	set_lstsizes(t_list **stack);
void	set_attributes(t_list **a, t_list **b);
void	set_distances(t_list *a, t_list *b);
void	set_directions(t_list *a, t_list *b);
int		calc_ind_cost(t_list *a, t_list *b);
int		calc_rr_cost(t_list *a, t_list *b);
int		calc_rrr_cost(t_list *a, t_list *b);
t_list	*find_cheapest_node(t_list *stack);
void	both_rotate(t_list **stack_a, t_list **stack_b);
void	both_reverse(t_list **stack_a, t_list **stack_b);
void	set_directions_list(t_list *a);
t_list	*find_smallest(t_list *stack);
int		check_ordered(t_list *a);
int		check_ordered_circular(t_list *a);
int		check_ordered_linear(t_list *a);
int		check_ordered_linear2(t_list *a, int til);
int		set_costs(t_list *a, t_list *b);
t_list	*previous_node(t_list **list, t_list *node);
void	set_attributes2(t_list **a, t_list **b);
int		check_ordered_circular(t_list *a);
void	reverse_rotate_together(t_data *data, t_list *a, t_list *b);
void	rotate_together(t_data *data, t_list *a, t_list *b);
void	rotate_individually(t_data *data, t_list *a, t_list *b);
void	init_data(t_data *data, char **argv);
int		check_if_int(char *str);
int		is_sign(char c);
void	check_for_empty_arg(char **argv);
int		is_all_space_or_sign(char *str);
void	init_data(t_data *data, char **argv);

#endif