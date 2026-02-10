/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:26:41 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/27 20:59:14 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define R_ERR 1
#define R_OK 0

void sort(char *argv)
{
	int i = 0;
	int j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (argv[i] > argv[j])
			{
				int tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void ft_putstr_n(char *s, int n)
{
	write(1, s, 1);
	write(1, '\n', 1);
}

void permute(char *s, int n, int *used, char *out, int pos)
{
	if (pos == n)//at end
		return (ft_putstr_n(s, n));

	int i = 0;
	while (i < n)
	{
		if (!used[i])
		{
			if (i > 0 && s[i - 1] == s[i] && !used[i - 1])
			{
				i++;
				continue ;
			}
			used[i] = 1;
			out[pos] = s[i];
			permute(s, n, used, out, pos + 1);
			used[i] = 0;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == 0)
		return 0;
	
	int n = strlen(argv[1]);

	char *s = (char *)malloc(sizeof(size_t) * n + 1);// copy of argv to sort
	if (!s)
		return (1);
	
	for (int i = 0; i < n; i++)
		s[i] = argv[1][i];
	s[n] = '\0';
	
	sort(s);
	
	int *used = (int *)calloc((size_t)n, sizeof(int));
	if (!used)
		return (free(s), R_ERR);
	char *out = (char *)malloc((size_t)n);
	if (!out)
		return (free(s), free(used), R_ERR);
	permute(s, n, used, out, 0);
}