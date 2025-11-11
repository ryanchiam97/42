/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:07:03 by rchiam            #+#    #+#             */
/*   Updated: 2025/06/14 18:21:02 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	printhex(unsigned int p, int caps, int count);
int	printnbr(int n, int i_unsigned, int count);
int	myftputstr(char *s);
int	uprintnbr(unsigned int n, int i_unsigned, int count);
int	handle_conversion(const char c, va_list *args);
int	isvalid(const char c);
int	printptr(unsigned long p, int caps, int count);

#endif