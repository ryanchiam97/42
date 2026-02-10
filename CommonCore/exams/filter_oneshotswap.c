/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_oneshotswap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:56:19 by rchiam            #+#    #+#             */
/*   Updated: 2026/02/10 22:49:01 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 10
#endif

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == 0)
		return (1);

	int readlen = 0;
	char *rtn_str = malloc(BUFFERSIZE + 1);
	if (!rtn_str)
		return (perror("Error"), 1);
	int totallen = 0;
	while ((readlen = read(0, &(rtn_str[totallen]), BUFFERSIZE)) > 0)
	{
		totallen += readlen;
		char *tmp = realloc(rtn_str, totallen + BUFFERSIZE + 1);
		if (!tmp)
			return (free(rtn_str), perror("Error"), 1);
		rtn_str = tmp;
	}
	if (readlen < 0)
		return (free(rtn_str), perror("Error"), 1);
	rtn_str[totallen] = '\0';

	
	int i = 0;
	char *filter = argv[1];
	int filterlen = strlen(filter);
	while (i < totallen)
	{
		int  j = 0;
		while (rtn_str[i + j] && filter[j] && j < filterlen && rtn_str[i + j] == filter[j])
			j++;
		if (j==filterlen)
		{
			int k = 0;
			while (k < filterlen)
			{
				write(1,"*",1);
				k++;
			}
			i+=filterlen;
		}
		else
		{
			write(1, rtn_str + i, 1);
			i++;
		}
	}
	free(rtn_str);
	return(0);
}

