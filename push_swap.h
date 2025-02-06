/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:53:37 by busseven          #+#    #+#             */
/*   Updated: 2025/02/06 17:10:31 by busseven         ###   ########.fr       */
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

#endif