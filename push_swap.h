/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:53:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/07 14:19:46 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"

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

#endif