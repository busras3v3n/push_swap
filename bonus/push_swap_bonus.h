/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:57:18 by busseven          #+#    #+#             */
/*   Updated: 2025/02/24 12:26:08 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../push_swap.h"

void	reverse_rotate_bonus(t_list **stack);
void	rotate_bonus(t_list **stack);
void	push_bonus(t_list **from, t_list **to);
void	swap_bonus(t_list **stack);
void	both_reverse_bonus(t_list **stack_a, t_list **stack_b);
void	both_rotate_bonus(t_list **stack_a, t_list **stack_b);
void	both_swap_bonus(t_list **stack_a, t_list **stack_b);
void	init_data_bonus(t_data *data, char **argv);
char	*get_next_line2(int fd, int k);
char	*add_chars(char *str, char a);
void	check_action(t_data *data, char *line);
void	check_arguments_bonus(char **numbers, t_data *data);

#endif