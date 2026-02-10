/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reviserip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:46:50 by rchiam            #+#    #+#             */
/*   Updated: 2026/02/10 21:58:18 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void getmin(char *str, int *rmL, int *rmR)
{
	int i = 0;
	int bal = 0;
	*rmL = 0;
	*rmR = 0;
	while (str[i])
	{
		if (str[i] == '(')
			bal++;
		else
		{
			if (bal == 0)
				(*rmR)++;
			else
				bal--;
		}
		i++;
	
	}
	*rmL = bal;
}

void dfs(char *str, int n, int idx, int rmR, int rmL, int bal, char *out)
{
	if (rmL + rmR > n - idx)
		return ;

	if (idx == n)
	{
		out[n] = '\0';
		if (rmR == 0 && rmL == 0 && bal == 0)
			puts(out);
		return ;
	}
	if (str[idx] == '(')
	{
		if (rmL > 0)
		{
			out[idx] = ' ';
			dfs(str, n, idx + 1, rmR, rmL - 1, bal, out);
		}
		out[idx] = '(';
		dfs(str, n, idx + 1, rmR, rmL, bal + 1, out);
	}
	else
	{
		if (rmR > 0)
		{
			out[idx] = ' ';
			dfs(str, n, idx + 1, rmR - 1, rmL, bal, out);
		}
		if (bal > 0)
		{
			out[idx] = ')';
			dfs(str, n, idx + 1, rmR, rmL, bal - 1, out);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	char *str = argv[1];
	int rmR = 0;
	int rmL = 0;
	getmin(str, &rmL, &rmR);
	int n = ft_strlen(str);
	char out[n + 1];
	dfs(str, n, 0, rmR, rmL, 0, out);
	return (0);
}