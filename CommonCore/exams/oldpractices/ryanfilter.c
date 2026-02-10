/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryanfilter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:54:03 by rchiam            #+#    #+#             */
/*   Updated: 2026/02/05 21:24:17 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 1
#endif

char *filter(char *pattern)
{
	char *rtnline;
	int readlen;
	int totallen;
	
	rtnline = calloc(BUFFERSIZE + 1, 1);
	if (!rtnline)
		return (perror("Error"), NULL);
	
	totallen = 0;
	readlen = BUFFERSIZE;

	//while((readlen = read(0, &(rtnline[totallen]), BUFFERSIZE)) > 0)
	while (!strchr(rtnline, '\n') && readlen > 0)
	// while (readlen == BUFFERSIZE)
	{
		readlen = read(0, &(rtnline[totallen]), BUFFERSIZE);
		if (readlen <= 0)
			break ;
		// if (readlen == -1)
			// return (free(rtnline), perror("Error"), 1);
		totallen += readlen;
		if (readlen == BUFFERSIZE)
		{
			rtnline = realloc(rtnline, totallen + BUFFERSIZE + 1);
			if (!rtnline)
				return (free(rtnline), perror("Error"), NULL);
		}
		rtnline[totallen] = '\0';
	}

	int i = 0;
	int len = (int)strlen(pattern);
	while (rtnline[i])
	{
		int j = 0;
		while (rtnline[i + j] && pattern[j] && rtnline[i + j] == pattern[j] && j < len)
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
	return (rtnline);
}

int	main(int argc, char **argv)
{
	char *line;
	
	if (argc != 2 || argv[1][0] == 0)
		return (1);
	while (1)
	{
		line = filter(argv[1]);
		if (!line || !line[0])
			break;
		printf("%s", line);
		free(line);
	}
}
