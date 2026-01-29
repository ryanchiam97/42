/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryanfilter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:54:03 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/29 22:23:15 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 10
#endif

int main(int argc, char **argv)
{
	char *rtnline;
	int readlen;
	int totallen;
	
	if (argc != 2 || argv[1][0] == 0)
		return (1);
	
	rtnline = malloc(BUFFERSIZE + 1);
	if (!rtnline)
		return (perror("Error:"), 1);
	
	totallen = 0;
	readlen = BUFFERSIZE;

	while (readlen == BUFFERSIZE)
	{
		readlen = read(0, &(rtnline[totallen]), BUFFERSIZE);
		if (readlen == -1)
			return (free(rtnline), perror("Error:"), 1);
		totallen += readlen;
		if (readlen == BUFFERSIZE)
		{
			rtnline = realloc(rtnline, totallen + BUFFERSIZE + 1);
			if (!rtnline)
				return (free(rtnline), perror("Error:"), 1);
		}
	}
	
	rtnline[totallen] = '\0';

	int i = 0;
	int len = (int)strlen(argv[1]);
	while (rtnline[i])
	{
		int j = 0;
		while (rtnline[i + j] && argv[1][j] && rtnline[i + j] == argv[1][j] && j < len)
			j++;
		if (j == len)
		{
			int k = i + j;
			while (i < k)
			{
				rtnline[i] = '*';
				i++;
			}
		}
		else
			i++;
	}
	printf("%s\n", rtnline);
	free(rtnline);
	return (0);
}
