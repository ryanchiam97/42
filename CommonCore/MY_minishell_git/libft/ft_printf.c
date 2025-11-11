/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:51:04 by twtan             #+#    #+#             */
/*   Updated: 2025/05/20 18:52:06 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// Reset the variable property to known value
void	ft_reset_vp(t_var *vp)
{
	vp->flags = 0;
	vp->type = 'n';
	vp->tmp_s = 0;
	vp->width = -1;
	vp->precision = -1;
	vp->spacepad = 0;
	vp->zeropad = 0;
	vp->sign = 0;
	vp->valid = 0;
}

static	int	ft_checkstr(const char *str, int *count)
{
	t_var	vp;

	if (str == 0)
		return (-1);
	if (*str == 0)
		return (0);
	*count = 0;
	while (*str != 0)
	{
		while ((*str != '%') && (*str != 0))
			str++;
		str = ft_varformat(str, &vp);
	}
	if ((vp.valid <= 0) && (vp.type == 0))
		return (-1);
	if ((vp.valid < 0) && (vp.type >= 'a') && (vp.type <= 'z'))
		return (-1);
	return (1);
}

// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer argument has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.
// printf("%*d", width, num);
// printf("%%2$*1$d '%2$*1$d'\n", 5, 42);
// %[$][flags][width][.precision][length modifier]conversion

// %p %s, use char *
// %d %i %u %x %X %c, use long
// %%

// vp - variable property
// This is the ft_printf mandatory prototype
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	t_var	vp;

	if (ft_checkstr(str, &count) < 1)
		return (ft_checkstr(str, &count));
	va_start(ap, str);
	while (*str != 0)
	{
		str = ft_txt(str, &count);
		str = ft_varformat(str, &vp);
		if (vp.type == '%')
			ft_prtchr('%', &count);
		else if (ft_strchr("cdiuxX", vp.type) != 0)
			ft_showvar_cdiuxx (va_arg(ap, int), &vp, &count);
		else if (vp.type == 's')
			ft_showvar_string(va_arg(ap, char *), &vp, &count);
		else if (vp.type == 'p')
			ft_showvar_ptr(va_arg(ap, void *), &vp, &count);
		else if ((vp.valid == -1) && (vp.type != 0))
			ft_show_invalid (&vp, &count);
	}
	va_end(ap);
	return (count);
}

/*****************************************************************************
* Testing block
*****************************************************************************/
/*
#include <stdio.h>

int	main(void)
{
	int	count;

	printf("printf '%%u %%j '\n");
	count = printf("%i %% %d end", -100, 30);
	printf (" total char : %d\n", count);
	count = ft_printf("%i %% %d end", -100, 30);
	printf (" total char : %d\n\n", count);
}*/
