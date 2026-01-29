/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:18:43 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/28 14:23:50 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl1.h"

long	ft_strchr_index(char *str, char c)
{
	long	idx;

	if (str == 0)
		return (-1);
	idx = 0;
	while (str[idx] != 0 && str[idx] != c)
		idx++;
	if (str[idx] == c)
		return (idx);
	return (-1);
}

char	*extend_buffer(char *buffer)
{
	char	*rtnstr;
	int		len;
	int		i;

	len = ft_strchr_index(buffer, 0);
	if (len == -1)
		len = 0;
	rtnstr = (char *)malloc(sizeof(char) * (len + BUFFER_SIZE + 1));
	if (!rtnstr)
		return (0);
	i = 0;
	while (i < len)
	{
		rtnstr[i] = buffer[i];
		i++;
	}
	rtnstr[i] = 0;
	free(buffer);
	return (rtnstr);
}

char	*return_nl_and_overwrite_buf(char *buffer)
{
	int		len;
	int		i;
	char	*rtnstr;

	if (!buffer)
		return (0);
	len = ft_strchr_index(buffer, '\n');
	if (len == -1)
		len = 0;

	rtnstr = (char *)malloc(sizeof(char) * (len + 2));
	if (!rtnstr)
		return (0);

	i = 0;
	while (buffer[i] != '\n')
	{
		rtnstr[i] = buffer[i];
		i++;
	}
	rtnstr[i] = buffer[i]; //'\n' index
	i++; // next index
	rtnstr[i] = 0;

	len = i;
	while (buffer[i] != 0)
	{
		buffer[i - len] = buffer[i];
		i++;
	}
	buffer[i - len] = buffer[i];//\0
	return (rtnstr);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*rtn_str;
	long		read_len;
	long		buffer_len;

	if ((fd < 0) || (fd > 1024))
		return (0);
	rtn_str = return_nl_and_overwrite_buf(buffer);
	read_len = BUFFER_SIZE;
	while (read_len == BUFFER_SIZE && rtn_str == 0)
	{
		buffer = extend_buffer(buffer);
		buffer_len = ft_strchr_index(buffer, 0);
		if (buffer_len == -1)
		{
			if (buffer != 0)
				free(buffer);
			buffer = 0;
		}
		read_len = read(fd, &(buffer[buffer_len]), BUFFER_SIZE);
		if (read_len == -1)
		{
			free(buffer);
			buffer = 0;
			return (0);
		}
		buffer_len += read_len;
		buffer[buffer_len] = 0;
		rtn_str = return_nl_and_overwrite_buf(buffer);
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

#include <stdio.h>

int	main(void)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(0);
		if (tmp == 0)
			return (printf("\n Error"), 1);
		if (tmp[0])
			return (printf("\n Empty, Exiting"), free(tmp), 1);
		printf(" %s", tmp);
		free(tmp);
	}
	return (0);
}
