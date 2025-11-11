/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:12:25 by twtan             #+#    #+#             */
/*   Updated: 2025/06/02 15:12:30 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 'ft_varformat' function
// This function extract details of %(flags, width, precision, type)
// s - string to extract variable format
// vp - variable property structure
// returns the pointer to end of %(details) on the string 's'.
const char	*ft_varformat(const char *s, t_var *vp)
{
	ft_reset_vp (vp);
	if (*s == '%')
	{
		vp->tmp_s = s++;
		s = ft_flag_coder (s, vp);
		s = ft_getnum (s, &(vp->width));
		if (*s == '.')
		{
			s = ft_getnum (++s, &(vp->precision));
			if (vp->precision == -1)
				vp->precision = 0;
		}
		if ((ft_strchr("cspdiuxX%", *s) != 0) && (*s != 0))
			vp->valid = 1;
		else
			vp->valid = -1;
		vp->type = *s;
		if (*s != 0)
			s++;
	}
	return (s);
}

// 'ft_show_invalid' function
// display the line when % input has an invalid type
//
// flag '-' bit 4
// flag '0' bit 3
// flag '#' bit 2
// flag ' ' bit 1
// flag '+' bit 0
void	ft_show_invalid(t_var *vp, int *count)
{
	ft_flags_switcher(vp);
	ft_prtchr('%', count);
	if (ft_readbit(2, &(vp->flags)) == 1)
		ft_prtchr('#', count);
	if (ft_readbit(1, &(vp->flags)) == 1)
		ft_prtchr(' ', count);
	if (ft_readbit(0, &(vp->flags)) == 1)
		ft_prtchr('+', count);
	if (ft_readbit(4, &(vp->flags)) == 1)
		ft_prtchr('-', count);
	if (ft_readbit(3, &(vp->flags)) == 1)
		ft_prtchr('0', count);
	if (vp->width != -1)
		(*count) += ft_showvar_num(vp->width);
	if (vp->precision != -1)
	{
		ft_prtchr('.', count);
		(*count) += ft_showvar_num(vp->precision);
	}
	if ((vp->type <= 'a') || (vp->type >= 'z'))
		ft_prtchr(vp->type, count);
}

// 'ft_showvar_string' function
// Display the string 'str' to stdout, if 'str' is 0 pointer prints '(null)'
// str - display to stdout
// count - increement this register for each charactor output to stdout
// returns -1 for invalid str ptr, 0 for empty str, 1 output to stdout
void	ft_showvar_string(char *str, t_var *vp, int *count)
{
	ft_update_var_str(str, vp);
	if (ft_readbit (4, &(vp->flags)) == 0)
		ft_padding(' ', vp->spacepad, count);
	if ((str == 0) && ((vp->precision == -1) || (vp->precision > 5)))
		ft_prtstr("(null)", 6, count);
	if ((str != 0) && (vp->precision >= 0))
		ft_prtstr(str, vp->precision, count);
	if ((str != 0) && (vp->precision < 0))
		ft_prtstr(str, ft_strlen(str), count);
	if (ft_readbit (4, &(vp->flags)) == 1)
		ft_padding(' ', vp->spacepad, count);
}

// 'ft_showvar_ptr' function
// Display the address of the pointer 'ptr' to stdout with formatting
// str - display to stdout
// count - increement this register for each charactor output to stdout
// returns -1 for invalid str ptr, 0 for empty str, 1 output to stdout
void	ft_showvar_ptr(void *ptr, t_var *vp, int *count)
{
	ft_update_var_ptr(ptr, vp);
	if (ft_readbit (4, &(vp->flags)) == 0)
		ft_padding(' ', vp->spacepad, count);
	if (vp->sign != 0)
		ft_prtchr(vp->sign, count);
	if (ptr == 0)
		ft_prtstr("(nil)", 5, count);
	else
	{
		ft_prtstr("0x", 2, count);
		ft_padding('0', vp->zeropad, count);
		*count += ft_showvar_hex((size_t)ptr, 'x');
	}
	if (ft_readbit (4, &(vp->flags)) == 1)
		ft_padding(' ', vp->spacepad, count);
}

// 'ft_showvar_cdiuxx' function
//
// Display the value of 'ld' (diuxX) to stdout with formatting
// str - display to stdout
// count - increement this register for each charactor output to stdout
// returns -1 for invalid str ptr, 0 for empty str, 1 output to stdout
void	ft_showvar_cdiuxx(long ld, t_var *vp, int *count)
{
	ft_update_var_cdiux(&ld, vp);
	if (ft_readbit (4, &(vp->flags)) == 0)
		ft_padding(' ', vp->spacepad, count);
	if (vp->sign != 0)
		ft_prtchr(vp->sign, count);
	if ((ft_readbit (2, &(vp->flags)) == 1) && (ld != 0))
	{
		ft_prtchr('0', count);
		ft_prtchr(vp->type, count);
	}
	ft_padding('0', vp->zeropad, count);
	if (vp->type == 'c')
		ft_prtchr(ld, count);
	if (((vp->type == 'd') || (vp->type == 'i'))
		&& !((ld == 0) && (vp->precision == 0)))
		(*count) += ft_showvar_num((long)ld);
	if ((vp->type == 'u') && !((ld == 0) && (vp->precision == 0)))
		(*count) += ft_showvar_num((unsigned int)ld);
	if (((vp->type == 'x') || (vp->type == 'X')) && !((ld == 0)
			&& (vp->precision == 0)))
		(*count) += ft_showvar_hex((unsigned int)ld, vp->type);
	if (ft_readbit (4, &(vp->flags)) == 1)
		ft_padding(' ', vp->spacepad, count);
}
