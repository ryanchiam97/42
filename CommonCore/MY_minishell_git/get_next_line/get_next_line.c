/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:08:02 by twtan             #+#    #+#             */
/*   Updated: 2025/06/22 22:04:35 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// func: free_buffer
// -ve fd trigger to free memory  
void	free_buffer(t_buf **lst, int fd)
{
	int	count;

	if (fd > 0)
		return ;
	count = -1;
	while (++count < 1024)
	{
		if (lst[count] != 0)
		{
			free (lst[count]->lbuf);
			free (lst[count]);
			lst[count] = 0;
		}
	}
}

// func: get_next_line
// Entry point for get next line, this is the bonus version
// Tracks multiple fd reads
// Create and return a string up to newline and
// return whatever is in the string buffer when EOF is met
// if fd is negative, free the buffer
char	*get_next_line(int fd)
{
	static t_buf	*lst[1024];
	ssize_t			status;
	char			*rbuf;
	char			*tmp_str;

	free_buffer(lst, fd);
	if ((fd < 0) || (fd > 1023) || (BUFFER_SIZE < 1))
		return (0);
	rbuf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (rbuf == 0)
		return (0);
	status = BUFFER_SIZE;
	tmp_str = ft_output_nl(&(lst[fd]), &status);
	while ((status == BUFFER_SIZE) && (tmp_str == 0))
	{
		status = read(fd, rbuf, BUFFER_SIZE);
		lst[fd] = ft_add2buf(&(lst[fd]), rbuf, &status);
		tmp_str = ft_output_nl(&(lst[fd]), &status);
		if (((status < BUFFER_SIZE) && (tmp_str == 0) && (status != -1)))
			tmp_str = ft_output_all(&(lst[fd]));
	}
	free(rbuf);
	return (tmp_str);
}
