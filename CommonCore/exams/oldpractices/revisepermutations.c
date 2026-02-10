/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revisepermutations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:08:58 by rchiam            #+#    #+#             */
/*   Updated: 2026/02/04 13:25:12 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *sort(char *str)
{
	int i = 0;
	while (str[i])
	{
		int j = i + 1;
		while (str[j])
		{
			if (str[j] < str[i])
			{
				char *tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (str);
}

void permute(char *s, int n, int *used, int pos, char *out)
{
	if (pos == n)
		return(printf("%s\n", out), 0);
	
	int i = 0;
	while (i < n)
	{
		if (!used[i])
		{
			if (i > 0 && s[i] == s[i - 1] && !used[i - 1])
			{
				i++;
				continue;
			}
			used[i] = 1;
			out[pos] = s[i];
			permute(s, n, used, pos + 1, out);
			used[i] = 0;
		}
		i++;
	}
	
}

int main(int argc, char **argv)
{
	if (argc !=2)
		return (0);
	char *str = argv[1];

	int len = (int)strlen(str);

	int *used = calloc((size_t)len, sizeof(int));
	char *out = malloc(len);
	if (!used || !out)
		return (1);

	sort(str);

	permute(str, len, used, 0, out);
	free(out);
	free(used);
	return (0);
}