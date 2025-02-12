/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:53:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/12 15:02:33 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				target;
	int				cost;
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

void check_for_invalid_char(char **ints, t_data *data);
void check_for_non_int(char **ints, t_data *data);
void check_for_doubles(char **ints, t_data *data);
int		get_2d_length(char **arr);
void	free_data_exit(t_data	*data);
void	free_2d_arr(char **arr);
t_list	*ft_beforelstlast(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
int	ft_lstsize(t_list *lst);
void	ft_lstswap(t_list *number1, t_list *number2);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	set_real_index(t_list **stack);
#endif