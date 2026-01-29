/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:57:11 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/28 12:44:22 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 100
#endif

#define RTN_ERR 1
#define RTN_OK 0

int main(int argc, char **argv)
{
	char *rd_str;
	int readlen;
	int bufferlen;

	if (argc != 2 || argv[1][0] == 0)
		return (0);

	rd_str = calloc(BUFFERSIZE + 1, sizeof(char));// cast to (* char)
	if (!rd_str)
		return (perror("Error:"), RTN_ERR);

	bufferlen = 0;
	readlen = BUFFERSIZE;

	while (readlen == BUFFERSIZE)
	{
		readlen = read(0, &(rd_str[bufferlen]), BUFFERSIZE);
		if (!readlen) // -1 not ! if error
			return (free(rd_str), perror("Error:"), RTN_ERR);
		bufferlen += readlen;
		// here on in must be inside if readlen == buffer... only extend when buffer fully read 
		rd_str = (char *)realloc(rd_str, BUFFERSIZE + readlen + 1);// wrong... 
		// no (char *)... realloc ok...
		// the size also wrong... it is bufferlen + Buffersize + 1
		if (!rd_str)
			return (perror("Error:"), RTN_ERR);
		rd_str[bufferlen] = '\0';// must be outside of whole while-loop
	}
	//
	char *tmp = rd_str;
	while (tmp)
	{
		tmp = (int *)memmem(rd_str, strlen(rd_str), argv[1], strlen(argv[1]));
		// wrong... (char *)... 
		// wrong... use tmp... not rd_str inside this function
		int i = 0;
		if (tmp)// wrong... while block... while (tmp && i < strlen(argv[1]))
		{
			while (i < strlen(argv[1]))
			{
				tmp[i] = '*';
				i++;
			}
		}
	}
	printf("%s", rd_str);
	free(rd_str);
	return (RTN_OK);
}
