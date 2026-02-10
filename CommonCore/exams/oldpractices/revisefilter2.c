/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revisefilter2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:31:39 by rchiam            #+#    #+#             */
/*   Updated: 2026/02/04 14:45:03 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 10
#endif

#define R_OK 0
#define R_ERR 1

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == 0)
		return (1);

	char *rtn_line = malloc(BUFFERSIZE + 1);
	if (!rtn_line)
		return (perror("Error:"), R_ERR);
	int readlen = BUFFERSIZE;
	int totallen = 0;
	while (readlen == BUFFERSIZE)
	{
		readlen = read(0, &(rtn_line[totallen]), BUFFERSIZE);
		if (readlen == -1)
			return(free(rtn_line), perror("Error:"), R_ERR);
		totallen += readlen;
		if (readlen == BUFFERSIZE)
		{
			char *tmp = realloc(rtn_line, totallen + BUFFERSIZE + 1);
			if (!tmp)
				return(free(rtn_line), perror("Error:"), R_ERR);
			rtn_line = tmp;
		}
	}
	rtn_line[totallen] = '\0';
	int i = 0;
	char *filter = argv[1];
	int filterlen = strlen(filter);
	while (rtn_line[i])
	{
		int j = 0;
		while (rtn_line[i + j] && filter[j] && rtn_line[i + j] == filter[j] && j < filterlen)
			j++;
		if (j == filterlen)
		{
			int k = i + j;
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
}