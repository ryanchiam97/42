/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:41:45 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/28 14:13:29 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 100
#endif

long find_char_index(char *str, char c)
{
	int i = 0;

	while (str[i] && str[i] != c)
		i++;
	if (i == c)
		return (i);
	return (-1);
}

char *extend_buffer(char *buffer)
{
	char 	*newbuffer;
	long		len;
	int		readlen;// wrong... use i

	len = ft_find_char_index(buffer, 0);// find buffer len + check
	//newbuffer = malloc len + buffersize + 1 ... and check
	// copy buffer to newbuffer len times
	// set null terminate
	// free buffer
	// return newbuffer
}

char *return_nl_overwrite_buffer(char *buffer)
{
	char *rtn_str;
	int	len;
	int	read_len;// wrong... use i... 

	// find index of \n (len)
	//  + checks... if error... len = 0
	// rtnstring malloc (len + 2)
	//copy buffer to rtnstr up to \n
	// set return str \n and \0
	// do overwrite...
	// in loop... i = 0
	// while (buffer[i])... buffer[i - len_of_rtn] = buffer[i], i++...
	// buffer[i] = 0
	// return rtnstr
}

char *get_next_line(int fd)
{
	static char	*buffer;// ok
	char 		*rtn_str;// ok
	int			readlen; // use long... ok
	int 		bufferlen;// use long ... ok

	if (fd < 0 || fd > 1024)
		return (0);// ok
	
	rtn_str = return_nl_overwrite_buffer(buffer);// first read... handle leftovers
	if (!rtn_str) // skip
		return (0);
	
	bufferlen = 0;// skip
	readlen = BUFFERSIZE;// ok

	while (readlen == BUFFERSIZE && rtn_str == 0)// ok. while buffer full and no \n yet
	{
		buffer = extend_buffer(buffer);// ok
		if(buffer == -1)
			return (free(rtn_str), 0);// if buffer !=0, free and zero it
		readlen = read(fd, &(buffer[bufferlen]), BUFFERSIZE);// ok
		if(readlen==-1)
			return (free(rtn_str), 0);// if buffer !=0, free and 0 it
		bufferlen += readlen;// ok
		buffer[bufferlen] = '\0';// ok
		rtn_str = return_nl_overwrite_buffer(buffer);// ok
		if(rtn_str==-1)// skip this check
			return (free(rtn_str), buffer = 0, 0);
	}
	if (rtn_str != 0)// ok... if \n found, return. normal case
		return (rtn_str);
	
	if (readlen == BUFFERSIZE)// wrong. if buffer[0] = 0...free and zero it, return 0. no input case(post last round)
	{
		free(buffer);
		buffer = 0;
		return (0);
	}
	
	if (rtn_str == 0)// skip if... rtnstr = buffer, buffer 0 and return rtnstr... (last round case)
	{
		rtn_str = buffer;
		free(buffer);
		return (rtn_str);
	}
}

int main(void)
{
	//
}