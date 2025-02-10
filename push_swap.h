/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:53:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/10 16:28:53 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>

typedef struct s_pushswap
{
	t_list	**a;
	t_list	**b;
	int		biggest_b;
	int		smallest_b;
}	t_pushswap;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		check_if_int(char *str);
void	check_for_doubles(char **argv);
void	check_for_invalid_char(char **argv);
void	check_for_non_int(char **argv);
int		is_sign(char c);
int		ft_lstsize(t_list *lst);
void	swap(t_list **stack, char *name);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	push(t_list **from, t_list **to, char *name);
void	rotate(t_list **stack, char *name);
void	reverse_rotate(t_list **stack, char *name);
void	both_swap(t_list **stack_a, t_list **stack_b);
void	both_rotate(t_list **stack_a, t_list **stack_b);
void	both_reverse(t_list **stack_a, t_list **stack_b);
t_list	*ft_beforelstlast(t_list *lst);
int	find_biggest(t_list **stack);
int	find_smallest(t_list **stack);
void	tiny_sort(t_list **a, char *name, int count);

#endif