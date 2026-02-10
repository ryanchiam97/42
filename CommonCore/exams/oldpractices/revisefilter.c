/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revisefilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:35:54 by rchiam            #+#    #+#             */
/*   Updated: 2026/02/04 12:54:17 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 10
#endif

#define R_OK 0
#define R_ERR 1

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == 0)
		return (R_ERR);

	int readlen = BUFFERSIZE;
	int totallen = 0;
	char *rtn_line = malloc(sizeof(char) * (BUFFERSIZE + 1));
	if (!rtn_line)
		return (perror("Error:"), R_ERR);
	while (readlen == BUFFERSIZE)
	{
		readlen = read(0, &(rtn_line[totallen]), BUFFERSIZE);
		if (readlen == -1)
			return (free(rtn_line), perror("Error:"), R_ERR);
		totallen += readlen;
		if (readlen == BUFFERSIZE)
		{
			rtn_line = realloc(rtn_line, totallen + BUFFERSIZE + 1);
			if (!rtn_line)
				return (free(rtn_line), perror("Error:"), R_ERR);
		}
	}
	rtn_line[totallen] = '\0';

	char *filter = argv[1];
	int filterlen = (int)strlen(filter);
	
	int i = 0;
	while (rtn_line[i])
	{
		int j = 0;
		while (rtn_line[i + j] && filter[j] && rtn_line[i + j] == filter[j] && j < filterlen)
			j++;
		int k = 0;
		if (j == filterlen)
		{
			k = j + i;
			while (i < k)
			{
				rtn_line[i] = '*';
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	printf("%s\n", rtn_line);
	free(rtn_line);
	return (R_OK);
}