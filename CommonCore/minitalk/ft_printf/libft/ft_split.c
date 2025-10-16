/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:18:54 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/12 15:24:26 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_wordcount(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

void	outputfree(char **output, int j)
{
	while (j >= 0)
		free(output[j--]);
	free(output);
}

int	split_handler(const char *str, char c, char **output)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > start)
		{
			output[j] = (char *)malloc(i - start + 1);
			if (output[j] == NULL)
				return (outputfree(output, j), -1);
			ft_strlcpy(output[j], &str[start], i - start + 1);
			j++;
		}
	}
	return (j);
}

char	**ft_split(char const *str, char c)
{
	char	**output;
	int		count;

	if (str == NULL)
	{
		output = (char **)malloc(sizeof(char *) * (1));
		output[0] = "";
		return (output);
	}
	output = (char **)malloc(sizeof(char *) * (get_wordcount(str, c) + 1));
	if (output == NULL)
		return (NULL);
	count = split_handler(str, c, output);
	if (count == -1)
		return (NULL);
	output[count] = NULL;
	return (output);
}

// #include <unistd.h>

// void	ft_putstr(char *str)
// {
// 	while (*str)
// 	{
// 		write(1, str, 1);
// 		str++;
// 	}
// }

// void	print_split_result(char **str_arr)
// {
// 	while (*str_arr)
// 	{
// 		ft_putstr(*str_arr);
// 		write(1, "\n", 1);
// 		str_arr++;
// 	}
// 	write(1, "\n\n", 2);
// }
// int	main(void)
// {
// 	char *str1;
// 	char *charset1;
// 	char **result1;
// 	char *str2;
// 	char *charset2;
// 	char **result2;
// 	char *str3;
// 	char *charset3;
// 	char **result3;
// 	char *str4;
// 	char *charset4;
// 	char **result4;
// 	char *str5;
// 	char *charset5;
// 	char **result5;
// 	char *str6;
// 	char *charset6;
// 	char **result6;
// 	char *str7;
// 	char *charset7;
// 	char **result7;

// 	str1 = "hello world";
// 	charset1 = " ";
// 	result1 = ft_split(str1, charset1);
// 	print_split_result(result1);
// 	str2 = "   split   this   string   ";
// 	charset2 = " ";
// 	result2 = ft_split(str2, charset2);
// 	print_split_result(result2);
// 	str3 = "abc";
// 	charset3 = "";
// 	result3 = ft_split(str3, charset3);
// 	print_split_result(result3);
// 	str4 = "";
// 	charset4 = " ";
// 	result4 = ft_split(str4, charset4);
// 	print_split_result(result4);
// 	str5 = ",,multiple,,separators,,";
// 	charset5 = ",";
// 	result5 = ft_split(str5, charset5);
// 	print_split_result(result5);
// 	str6 = "one two three";
// 	charset6 = " o";
// 	result6 = ft_split(str6, charset6);
// 	print_split_result(result6);
// 	str7 = NULL;
// 	charset7 = " ";
// 	result7 = ft_split(str7, charset7);
// 	print_split_result(result7);
// 	return (0);
// }