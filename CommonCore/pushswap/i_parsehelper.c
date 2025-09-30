/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_parsehelper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:34:45 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/30 21:09:50 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	index_arr(int **int_arr, int size)
{
	int	*temp;
	int	i;
	int	j;
	int	rank;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return ;
	i = 0;
	while (i < size)
	{
		rank = 1;
		j = 0;
		while (j < size)
		{
			if ((*int_arr)[i] > (*int_arr)[j])
				rank++;
			j++;
		}
		temp[i] = rank;
		i++;
	}
	while (size--)
		(*int_arr)[size] = temp[size];
	free(temp);
}

int	determinepower(int max)
{
	int	power;

	if (max == 0)
		return (1);
	power = 0;
	while (max != 0)
	{
		max >>= 1;
		power++;
	}
	return (power);
}

int	get_char_arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	freestrarr(char **char_arr)
{
	int	i;

	i = 0;
	while (char_arr[i])
		free(char_arr[i++]);
	free(char_arr);
}

int	*parseinput(char *input, int *returnsize)
{
	char		**char_arr;
	int			*int_arr;
	long long	outcome;
	int			size;

	char_arr = ft_split(input, ' ');
	if (!char_arr)
		return (NULL);
	size = get_char_arr_size(char_arr);
	int_arr = malloc(sizeof(int) * size);
	if (!int_arr || checkargvissues(size, char_arr))
		return (freestrarr(char_arr), free(int_arr), NULL);
	*returnsize = size;
	while (size--)
	{
		outcome = ft_atoi(char_arr[size]);
		if (outcome > (long long)INT_MAX || outcome < (long long)INT_MIN)
			return (free(char_arr[size]), NULL);
		else
			int_arr[size] = outcome;
		free(char_arr[size]);
	}
	return (free(char_arr), int_arr);
}
