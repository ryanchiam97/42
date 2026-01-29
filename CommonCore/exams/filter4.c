/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:44:52 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/29 20:33:30 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 12
#endif

#define RTN_ERR 1
#define RTN_OK 0

int main (int argc, char ** argv)
{
	char	*rd_str;
	int		readlen;
	int		bufferlen;

	if (argc != 2 || argv[1][0] == 0)
		return (perror("Error:"), 1);

	rd_str = calloc(BUFFERSIZE + 1, sizeof(char));
	if (!rd_str)
		return (perror("Error:"), RTN_ERR);

	bufferlen = 0;
	readlen = BUFFERSIZE;

	while (readlen == BUFFERSIZE)
	{
		readlen = read(0, &(rd_str[bufferlen]), BUFFERSIZE);
		if (readlen == -1)
			return (free(rd_str), perror("Error:"), RTN_ERR);
		bufferlen += readlen;
		if (readlen == BUFFERSIZE)
		{
			rd_str = (char *)realloc(rd_str, bufferlen + BUFFERSIZE + 1);
			if (!rd_str)
				return (free(rd_str), perror("Error:"), RTN_ERR);
		}
	}
	rd_str[bufferlen] = '\0';
	char *tmp = rd_str;
	while (tmp)
	{
		tmp = (char *)memmem(tmp, strlen(tmp), argv[1], strlen(argv[1]));
		int i = 0;
		while (tmp && i < (int)strlen(argv[1]))
		{
			tmp[i] = '*';
			i++;
		}
	}
	printf("%s", rd_str);// add \n
	free(rd_str);
	return (RTN_OK);
}
