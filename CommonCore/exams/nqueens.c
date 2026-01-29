/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:44:39 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/27 20:12:09 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void	printsolution(int *columns)
{
	int i = 0;
	while (columns[i])
	{
		printf("%i ", columns[i]);
		i++;
	}
	printf("\n");
}

int isok(int r, int c, int *col)
{
	for (int pc = 0; pc < c; pc++)
	{
		int pr = col[pc];
		if (pr == r)
			return 0;
		if (abs(pr - r) == abs(pc - c))
			return 0;
	}
	return 1;
}

void solve(int* col, int c, int n)
{
	if (c == n)
		return (printsolution(col));
	
	for (int r = 0; r < c; r++)
	{
		if (!isok(r, c, col))
			continue ;
		col[c] = r;
		solve(col, c + 1, n);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int n = atoi(argv[1]);
	if (n < 0 || n > INT_MAX)
		return (1);
	int *columnrecord = (int *)malloc(sizeof(int) * n);
	if (!columnrecord)
		return (1);
	solve(columnrecord, 0, n);
	free(columnrecord);
	return 0;
}
