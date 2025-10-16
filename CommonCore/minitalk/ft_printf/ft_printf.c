/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:12:53 by rchiam            #+#    #+#             */
/*   Updated: 2025/06/14 22:51:57 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(const char c, va_list *args)
{
	void	*ptr;

	if (c == '%')
		return (write(1, "%", 1), 1);
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1), 1);
	else if (c == 's')
		return (myftputstr(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (printnbr(va_arg(*args, int), 0, 0));
	else if (c == 'u')
		return (uprintnbr(va_arg(*args, unsigned int), 1, 0));
	else if (c == 'p')
	{
		ptr = va_arg(*args, void *);
		if (!ptr)
			return (write(1, "(nil)", 5), 5);
		return (2 + printptr((unsigned long)ptr, -1, 0));
	}
	else if (c == 'x')
		return (printhex(va_arg(*args, unsigned int), 0, 0));
	else if (c == 'X')
		return (printhex(va_arg(*args, unsigned int), 1, 0));
	return (write(1, &c, 1), 1);
}

int	isvalid(const char c)
{
	char	*s;
	int		i;

	s = "cpidusxX%";
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (isvalid(*input))
				count += handle_conversion(*input, &args);
			else
				return (-1);
			input++;
		}
		else
		{
			write(1, input, 1);
			input++;
			count++;
		}
	}
	return (count);
}

// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
// 	char	*s;
// 	char	*p;
// 	int		count1;
// 	int		count2;

// 	s = "hello";
// 	p = 0;
// 	// count1 = printf("theirs: %u, %%, %c, %s, %p, %x, %X, %s, %p",
// 	// 		 -1, 'c', s, s, 0x123, 42, 0, p);
// 	// printf("\n");
// 	// count2 = ft_printf("mine:   %u, %%, %c, %s, %p, %x, %X, %s, %p", 
// 	// 		-1, 'c', s, s, 0x123, 42, 0, p);
// 	// printf("\n");
// 	count1 = ft_printf("%p and %p", LONG_MAX, LONG_MIN);
// 	printf("\n");
// 	count2 = printf("%p and %p", LONG_MAX, LONG_MIN);
// 	count1 = printf(" %p %p \n", LONG_MIN, LONG_MAX);
// 	count2 = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
// 	printf("theirs: %i and mine: %i", count1, count2);
// }
// print("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d
// TEST(23, print(" %d ", INT_MIN));
// TEST(24, print(" %d ", LONG_MAX));

// TEST(26, print(" %d ", UINT_MAX));
// TEST(27, print(" %d ", ULONG_MAX));
// TEST(28, print(" %d ", 9223372036854775807LL));
// TEST(29, print(" %d %d %d %d %d %d %d", 
// // INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));