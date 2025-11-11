/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:06:46 by twtan             #+#    #+#             */
/*   Updated: 2025/10/30 21:06:51 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split_r.h"

// func: ft_free_split_arr
// free all the allocated memory for ft_split_r
// check each element address is within the element string
// if not within the address, then it might have been modified externally and
// require additional freeing of memory  
// zero the memory address to denote freed  
// return 0 for successfull
// return -1 for unsuccessfull
int	ft_free_split_arr(char ***arr)
{
	int		arr_idx;
	char	*start_pt;
	char	*end_pt;
	char	*tmp_pt;

	if (*arr == 0)
		return (-1);
	arr_idx = 0;
	while ((*arr)[arr_idx] != 0)
		arr_idx++;
	start_pt = (*arr)[arr_idx + 1];
	end_pt = (*arr)[arr_idx + 2];
	while (--arr_idx >= 0)
	{
		tmp_pt = start_pt;
		while ((tmp_pt < end_pt) && (tmp_pt != (*arr)[arr_idx]))
			tmp_pt++;
		if (tmp_pt == end_pt)
			free((*arr)[arr_idx]);
	}
	if (start_pt != 0)
		free (start_pt);
	free (*arr);
	*arr = 0;
	return (0);
}

// func: ft_split_counter
// count the number of 'words' separated by delimiters
// strlen : returns the element string length to allocate
// return the number of 'words' in the str
// if delimiter is null, the whole string is a word, word count is 1
static int	ft_split_counter(const char *str, char delimiter, int *strlen)
{
	int	word_count;
	int	idx;

	*strlen = 0;
	word_count = 0;
	idx = 0;
	while (str[idx] != 0)
	{
		while ((str[idx] == delimiter) && (str[idx] != 0))
			idx++;
		if ((str[idx] != delimiter) && (str[idx] != 0))
			word_count++;
		while ((str[idx] != delimiter) && (str[idx] != 0))
		{
			idx++;
			(*strlen)++;
		}
		while ((str[idx] == delimiter) && (str[idx] != 0))
			idx++;
		if (str[idx] != 0)
			(*strlen)++;
	}
	if (delimiter == 0)
		return (1);
	return (word_count);
}

// func: ft_split_strtrimcopy
// copy and trim the string
// multiple delimiter cluster will be reduce to single delimiter
// delimiters at start and end will be remove  
static void	ft_split_trimcopy(const char *str, char *new_str, char delimiter)
{
	int	idx;
	int	new_idx;

	idx = 0;
	new_idx = 0;
	while (str[idx] != 0)
	{
		while ((str[idx] == delimiter) && (str[idx] != 0))
			idx++;
		while ((str[idx] != delimiter) && (str[idx] != 0))
			new_str[new_idx++] = str[idx++];
		while ((str[idx] == delimiter) && (str[idx] != 0))
			idx++;
		if (str[idx] != 0)
			new_str[new_idx++] = delimiter;
	}
	new_str[new_idx] = 0;
}

// func: ft_split_linker
// Link the array elements to the new string
// replace delimiter as null, so element will appear as 1 word
static void	ft_split_linker(char **arr, char *new_str, char delimiter)
{
	int	str_idx;
	int	arr_idx;

	str_idx = 0;
	arr_idx = 0;
	while (new_str[str_idx] != 0)
	{
		arr[arr_idx++] = new_str + str_idx;
		while ((new_str[str_idx] != delimiter) && (new_str[str_idx] != 0))
			str_idx++;
		if (new_str[str_idx] != 0)
			new_str[str_idx++] = 0;
	}
	arr[arr_idx] = 0;
	arr[++arr_idx] = new_str;
	arr[++arr_idx] = new_str + str_idx;
}

// func: ft_split_r
// Simple split of text, split at delimiter
// Return an array of each 'word' in the str 
char	**ft_split_r(const char *str, char delimiter)
{
	int		tmp;
	int		str_len;
	char	**str_arr;
	char	*new_str;

	tmp = ft_split_counter(str, delimiter, &str_len);
	str_arr = (char **)malloc(sizeof(char *) * (tmp + 3));
	if (str_arr == 0)
		return (0);
	if ((str == 0) || (*str == 0))
	{
		tmp = -1;
		while (++tmp < 3)
			str_arr[tmp] = 0;
		return (str_arr);
	}
	new_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (new_str == 0)
		free(str_arr);
	if (new_str == 0)
		return (0);
	ft_split_trimcopy(str, new_str, delimiter);
	ft_split_linker(str_arr, new_str, delimiter);
	return (str_arr);
}

/*
// test for this function
#include <stdio.h>

int	main (void)
{
	int	count;
	int	str_len;
	char	*element;
	char	**arr;
	char	*test;
	char	delimiter;
	int	idx;
	
	test = " This is a  test  ";
	//test = "";
	delimiter = ' ';
	printf("\n test str: '%s'     delimiter: '%c'\n", test, delimiter);
	count = ft_split_counter(test, delimiter, &str_len);
	printf("\n count: %d    strlen: %d\n", count, str_len);
	element = (char *)malloc(sizeof(char) * (str_len + 1));
	ft_split_trimcopy(test, element, delimiter);
	printf("\n new string: '%s'\n", element);
	free (element);
	arr = ft_split_r(test, delimiter);
	count = -1;
	while (arr[++count] != 0)
		printf("\n [%d] '%s' ", count, arr[count]);
	idx =0;
	printf("\n\nAfter insert\n");
	arr[idx] = (char *)malloc(sizeof(char) * 5);
	arr[idx][0] = '-';
	arr[idx][1] = '+';
	arr[idx][2] = '+';
	arr[idx][3] = '-';
	arr[idx][4] = 0;
	count = -1;
	while (arr[++count] != 0)
		printf("\n [%d] '%s' ", count, arr[count]);
	printf("\n Before free, arr address: %p ", arr);
	ft_free_split_arr(&arr);
	printf("\n After free, arr address: %p \n", arr);
	return (0);
}
*/
