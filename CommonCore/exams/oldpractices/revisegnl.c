/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revisegnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:52:07 by rchiam            #+#    #+#             */
/*   Updated: 2026/02/04 14:49:15 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 10
#endif

int getcharindex(char *str, char c)
{
	if (!str)
		return (-1);
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char *extend_buffer(char *buffer)
{
	int bufferlen = getcharindex(buffer, 0);
	if (bufferlen = -1)
		return (0);
	char *newbuf = malloc(sizeof(char) * (bufferlen + BUFFERSIZE + 1));
	if (!newbuf)
		return (0);
	int i = 0;
	while (i < bufferlen)
	{
		newbuf[i] = buffer[i];
		i++;
	}
	newbuf[i] = '\0';
	free(buffer);
	return (newbuf);	
}

char *return_nl_overwrite(char *buffer)
{
	if (!buffer)
		return (-1);
	int nl = getcharindex(buffer, '\n');
	if (nl == -1)
		return (free(buffer), -1);
	if (nl == 0)
		return (0);
	char *rtn_str = malloc(nl + 2);
	if (!rtn_str)
		return (free(buffer), 0);
	int i = 0;
	while (i < nl)
	{
		rtn_str[i] = buffer[i];
		i++;
	}
	rtn_str[i] = buffer[i];
	i++;
	rtn_str[i] = '\0';
	int j = 0;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	return (rtn_str);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *rtn_str;
	int bufferlen;
	int readlen;
	
	if (fd < 0 || fd > 1024)
		return (0);
	
	readlen = BUFFERSIZE;
	rtn_str = return_nl_overwrite(buffer);
	
	while (readlen == BUFFERSIZE && rtn_str == 0)
	{
		buffer = extend_buffer(buffer);
		bufferlen = getcharindex(buffer, 0);
		if (bufferlen == -1)
		{
			if (!buffer)
				free(buffer);
			buffer = 0;
		}
		readlen = read(fd, &(buffer[bufferlen]), BUFFERSIZE);
		if (readlen == -1)
			return (free(buffer), buffer = 0, 0);
		bufferlen += readlen;
		buffer[bufferlen] = '\0';
		rtn_str = return_nl_overwrite(buffer);
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

int main(void)
{
	char *tmp;

	while (1)
	{
		tmp = get_next_line(0);
		if (tmp == 0)
			return (printf("Error"), 1);
		if (tmp[0])
			return (printf("Empty"), free(tmp), 1);
		printf("%s", tmp);
		free(tmp);
	}
	return (0);
}