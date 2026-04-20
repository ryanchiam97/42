#include "get_next_line.h"

long	ft_strchr_idx(char *str, char c)
{
	long	idx;
	
	if (str == 0)
		return (-1);
	idx = 0;
	while ((str[idx] != 0) && (str[idx] != c))
		idx++;
	if (str[idx] == c)
		return (idx);
	return (-1);
}

char	*gnl_extend_buffer(char *buffer)
{
	char	*rtn_str;
	long	len;
	long	idx;

	len = ft_strchr_idx(buffer, 0);
	if (len == -1)
		len = 0;
	rtn_str = (char *)malloc(sizeof(char) * (len + BUFFER_SIZE + 1));
	if (rtn_str == 0)
		return (0);
	idx = -1;
	while (++idx < len)
		rtn_str[idx] = buffer[idx];
	rtn_str[idx] = 0;
	free (buffer);
	return (rtn_str);
}

char	*gnl_rtn_nl(char *buffer)
{
	char	*rtn_str;
	long	len;
	long	idx;

	len = ft_strchr_idx(buffer, '\n');
	if (len == -1)
		return (0);

	rtn_str = (char *)malloc(sizeof(char) * (len + 2));
	if (rtn_str == 0)
		return (0);
	
	idx = -1;
	while (buffer[++idx] != '\n')
		rtn_str[idx] = buffer[idx];
	rtn_str[idx] = buffer[idx];
	rtn_str[idx + 1] = 0;
	
	len = idx + 1;
	while (buffer[++idx] != 0)
		buffer[idx - len] = buffer[idx];
	buffer[idx - len] = buffer[idx];
	return (rtn_str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*rtn_str;
	long		buf_len;
	long		rd_len;

	if ((fd < 0) || (fd > 1024))
		return (0);
	
	rtn_str = gnl_rtn_nl(buffer);
	rd_len = BUFFER_SIZE;
	while ((rd_len == BUFFER_SIZE) && (rtn_str == 0))
	{
		buffer = gnl_extend_buffer(buffer);
		buf_len = ft_strchr_idx (buffer, 0);
		if (buf_len == -1)
		{
			if (buffer != 0)
				free (buffer);
			buffer = 0;
			return (0);
		}
		rd_len = read(fd, &(buffer[buf_len]), BUFFER_SIZE);
		if (rd_len == -1)
		{
			free (buffer);
			buffer = 0;
			return(0);
		}
		buf_len += rd_len;
		buffer[buf_len] = 0;
		rtn_str = gnl_rtn_nl(buffer);
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
/*
#include <stdio.h>

int	main(void)
{
	char	*tmp;
	
	while (1)
	{
		tmp = get_next_line(0);
		
		if (tmp == 0)
		{
			printf ("\n Fault...");
			return (1);
		}
		if (tmp[0] == 0)
		{
			printf ("\n empty, exiting...");
			free (tmp);
			return (0);
		}
		printf (" %s", tmp);
		free (tmp);
	}
	return (0);
}*/
