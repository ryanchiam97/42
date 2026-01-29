/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:13:49 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/28 14:38:39 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 100
#endif

long ft_strchr_index(char *str, char c)
{
	long i = 0;

	while (str[i] && str[i] != c)
		i++;
	if (c == str[i])
		return i;
	return (-1);
}

char *extend_buffer(char *buffer)
{
	long i;
	char *new_buf;
	long len;
}

char *return_nl_overwrite_buf(char *buffer)
{
	long i;
	long len;
	char *rtn_str;

	//
}


char *get_next_line(int fd)
{
	static char *buffer;
	char *rtn_str;
	long	readlen;
	long	bufferlen;

	if (fd < 0 || fd > 1024)
		return (0);
	rtn_str = return_nl_overwrite_buf(buffer);
	readlen = BUFFERSIZE;
	while (readlen == BUFFERSIZE && rtn_str == 0)
	{
		buffer = extend_buffer(buffer);
		bufferlen = ft_strchr_index(buffer, 0);
		if (bufferlen == -1)
		{
			if (buffer != 0)
				free(buffer);
			return (0);
		}
		readlen = read(fd, &(buffer[bufferlen]), BUFFERSIZE);
		if (readlen == -1)
		{
			free(buffer);
			buffer = 0;
			return (0);
		}
		bufferlen += readlen;
		buffer[bufferlen] = 0;
		rtn_str = return_nl_overwrite_buf(buffer);
	}
	if (rtn_str != 0)
		return (rtn_str);

	if (buffer[0] == 0)
	{
		free(buffer);
		buffer = 0;
		return (0);
	}
	rtn_str = buffer;
	buffer = 0;
	return (rtn_str);
}

int main()
{
	//print gnl
}