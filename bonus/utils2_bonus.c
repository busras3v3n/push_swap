/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:14:53 by busseven          #+#    #+#             */
/*   Updated: 2025/02/17 17:17:39 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

int	free_buffer(int k, char *buffer)
{
	if (k == 0)
	{
		if (buffer)
			free(buffer);
		return (0);
	}
	return (1);
}
char	*get_next_line2(int fd, int k)
{
	static char	*buffer[1024];
	char		*next_line;

	if (!free_buffer(k, buffer[fd]))
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (ft_findnewline(buffer[fd]) == -1)
		next_line = ft_substr(buffer[fd], 0, ft_strlen(buffer[fd]));
	else
		next_line = ft_substr(buffer[fd], 0, ft_findnewline(buffer[fd]) + 1);
	if (!next_line)
		return (NULL);
	if (next_line[0] == '\0')
	{
		free(next_line);
		free(buffer[fd]);
		return (NULL);
	}
	buffer[fd] = new_buffer(buffer[fd]);
	return (next_line);
}
