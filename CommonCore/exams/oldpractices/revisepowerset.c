/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revisepowerset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:25:31 by rchiam            #+#    #+#             */
/*   Updated: 2026/02/10 22:36:50 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void printsubset(int* subset, int len)
{
	int i = 1;

	printf("%i", subset[0]);
	
	while (i < len)
	{
		printf(" %i", subset[i]);
		i++;
	}
	printf("\n");
}

void dfs(int idx, int max, int target, int *val, int *subset, int len, int sum)
{
	if (idx == max)
	{
		if (target == sum)
			printsubset(subset, len);
		return;
	}
	dfs(idx + 1, max, target, val, subset, len, sum);
	subset[len] = val[idx];
	dfs(idx + 1, max, target, val, subset, len + 1, sum + val[idx]);
}
int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	int max = argc - 2;
	int target = atoi(argv[1]);
	
	int *val = malloc(max * sizeof(int));
	int *subset = malloc(max * sizeof(int));
	if (!val || !subset)
		return (0);
	
	int i = 0;
	while (i < max)
	{
		val[i] = atoi(argv[i + 2]);
		i++;
	}
	
	dfs(0, max, target, val, subset, 0, 0);
	free(val);
	free(subset);	
}
