/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newfilter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:25:28 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/29 21:53:52 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFERSIZE
# define BUFFERSIZE 10
#endif

char* ft_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int ft_strncmp(char *s1, char *s2)
{
	int i = 0;
	int n = (int)strlen(s2);

	while (i < n && s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	if (n == i)
		return (0);
	return (s1[i] - s2[i]);
}

void search_replace(char *str, char* replace)
{
	int i = 0;
	int len = (int)strlen(replace);
	while (str[i])
	{
		printf("ttest3\n");
		if (ft_strncmp(str, replace) == 0)
		{
			int j = 0;
			while(j < len)
			{
				write(1,"*",1);
				i++;
				j++;
			}
		}
		else
		{
			write(1, str + i, 1);
			i++;
		}
	}
}

int main (int argc, char** argv)
{
	static char 	buffer[BUFFERSIZE + 1];
	char 			*line;
	int				readlen;
	int				bytetotal;

	// check arguments
	if (argc != 2)
		return (perror("Error:"), 1);
	
	// malloc rtn line
	line = malloc(1000000);
	if (!line)
		return (perror("Error:"), 1);
	
	bytetotal = 0;
	
	while ((readlen = read(0, buffer, BUFFERSIZE)) > 0)
	{
		printf("ttest\n");
		ft_strncpy(line + bytetotal, buffer, readlen);
		bytetotal = bytetotal + readlen;
	}
	printf("ttest4\n");
	if (readlen < 0)
		return (perror("Error:"), 1);
	line[bytetotal] = '\0';
	search_replace(line, argv[1]);
	printf("%s\n", line);
	free(line);
	return (0);
}
