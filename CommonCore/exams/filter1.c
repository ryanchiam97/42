/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:14:35 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/29 20:32:44 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE

#ifndef BUFFERSIZE
# define BUFFERSIZE 100
#endif

#define RTN_ERR 1
#define RTN_OK 0

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	char *rd_str;
	int bufferlen;
	int readlen;

	//check args
	if (argc != 2 || argv[1][0] == 0)
		return (RTN_ERR);

	// calloc readstr()
	rd_str = (char *)calloc(sizeof(char), (BUFFERSIZE + 1));
	if (!rd_str)
		return (perror("Error"), RTN_ERR);

	// init bufferlen to 0 and readlen=buffer size to start loop
	bufferlen = 0;
	readlen = BUFFERSIZE;

	// while fully reading each buffer...
	while (readlen == BUFFERSIZE)
	{
		// readlen => read into buffer at the address of the \0
		readlen = read(0, &(rd_str[bufferlen]), BUFFERSIZE);
		if (readlen == -1)
			return (free(rd_str), perror("Error"), RTN_ERR);
		// add the readlen to bufferlen
		bufferlen += readlen;
		// if the readlen == buffersize(meaning filled)...
		if (readlen == BUFFERSIZE)
		{
			// realloc readstr to add buffersize
			rd_str = realloc(rd_str, bufferlen + BUFFERSIZE + 1);
			if (!rd_str)
				return (free(rd_str), perror("Error"), RTN_ERR);
		}
	}

	// set readstr [bufferlen] to \0 
	rd_str[bufferlen] = '\0';

	// tmp =readstr
	char *tmp = rd_str;
	// while tmp (cos memmem will return null if not found)
	while (tmp)
	{
		// haystack, haystack len, needle, needle len
		// convert to (char *)
		tmp = (char *)memmem(tmp, strlen(tmp), argv[1], strlen(argv[1]));
		int i = 0;
		// tmp now is the address to substring...
		while (tmp && i < (int)strlen(argv[1]))
		{
			tmp[i] = '*';
			i++;
		}
	}

	printf("%s\n", rd_str);

	free(rd_str);
	return (RTN_OK);
}
