/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:16:46 by twtan             #+#    #+#             */
/*   Updated: 2025/06/03 19:16:49 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// Update var format value and turn off incompatible flags

// 'ft_flags_switcher' function 
// Deactivates the flags that is not compatible with the provide type.
// Also check against other flags and deactivates less priority flag.
//	
// flag '-' bit 4
// flag '0' bit 3
// flag '#' bit 2
// flag ' ' bit 1
// flag '+' bit 0
void	ft_flags_switcher(t_var *vp)
{
	if ((vp->type == 's') || (vp->type == 'c'))
		vp->flags &= 0b11110000;
	if (vp->type == 'c')
		vp->precision = -1;
	if (vp->type == 'u')
		vp->flags &= 0b11111000;
	if ((vp->type == 'd') || (vp->type == 'i'))
		vp->flags &= 0b11111011;
	if ((vp->type == 'x') || (vp->type == 'X'))
		vp->flags &= 0b11111100;
	if (vp->type == 'p')
		vp->flags &= 0b11111011;
	if ((vp->precision > 0) && (vp->valid == 1))
		ft_clearbit (3, &(vp->flags));
	if (ft_readbit (4, &(vp->flags)) == 1)
		ft_clearbit (3, &(vp->flags));
	if (ft_readbit (0, &(vp->flags)) == 1)
		vp->flags &= 0b11111101;
}

// 'ft_update_var_ptr' function 
// Calculate the space and zero padding needed for formatting a string output.
void	ft_update_var_str(void *str, t_var *vp)
{
	int	char_count;

	ft_flags_switcher(vp);
	char_count = 6;
	if ((vp->precision < 6) && (vp->precision != -1))
		char_count = 0;
	if (str != 0)
	{
		char_count = ft_strlen(str);
		if ((vp->precision < char_count) && (vp->precision != -1))
			char_count = vp->precision;
	}
	if (vp->width > char_count)
		vp->spacepad = vp->width - char_count;
}

// 'ft_update_var_ptr' function 
// Calculate the space and zero padding needed for formatting the output.
//
// flag '-' bit 4
// flag '0' bit 3
// flag '#' bit 2
// flag ' ' bit 1
// flag '+' bit 0
void	ft_update_var_ptr(void *ptr, t_var *vp)
{
	int	char_count;

	ft_flags_switcher(vp);
	char_count = ft_countnum((unsigned long)ptr, vp->type);
	if (ptr == 0)
		char_count = 5;
	if (ft_readbit(0, &(vp->flags)) && (vp->sign == 0) && (ptr != 0))
		vp->sign = '+';
	if (ft_readbit(1, &(vp->flags)) && (vp->sign == 0) && (ptr != 0))
		vp->sign = ' ';
	if (vp->precision > char_count)
		vp->zeropad = vp->precision - char_count;
	if (ft_readbit(3, &(vp->flags)) && (ptr != 0))
		vp->zeropad = vp->width - char_count - 2;
	if (ft_readbit(3, &(vp->flags)) && (vp->sign != 0) && (ptr != 0))
		vp->zeropad--;
	if ((vp->zeropad < 0) || (ptr == 0))
		vp->zeropad = 0;
	if (vp->width > vp->zeropad + char_count + 2)
		vp->spacepad = vp->width - vp->zeropad - char_count - 2;
	if ((ptr == 0) && (vp->width > char_count))
		vp->spacepad = vp->width - 5;
	if ((vp->sign != 0) && (vp->spacepad > 0))
		vp->spacepad--;
}

// 'ft_sign_adjust' function
// A helper function for 'ft_update_var_diux' function
// Extract the sign out and absolute 'ld'
static void	ft_sign_adjust(long *ld, t_var *vp)
{
	ft_flags_switcher(vp);
	if ((*ld < 0) && ((vp->type == 'd') || (vp->type == 'i')))
	{
		vp->sign = '-';
		*ld *= -1;
	}
	if ((ft_readbit (0, &(vp->flags)) == 1) && (vp->sign == 0))
		vp->sign = '+';
	if ((ft_readbit (1, &(vp->flags)) == 1) && (vp->sign == 0))
		vp->sign = ' ';
}

// 'ft_update_var_diux' function 
// Handles formatting for cdiuxX
// Calculate the space and zero padding needed for formatting the output.
// 
// Calls function 'ft_flags_switcher' to do the following...
// Deactivates the flags that is not compatible with the provided type.
// Also check against other flags and deactivates less priority flag.
// flag '-' bit 4
// flag '0' bit 3
// flag '#' bit 2
// flag ' ' bit 1
// flag '+' bit 0
void	ft_update_var_cdiux(long *ld, t_var *vp)
{
	int	char_count;

	ft_sign_adjust (ld, vp);
	char_count = 1;
	if ((vp->type == 'd') || (vp->type == 'i'))
		char_count = ft_countnum(*ld, vp->type);
	if ((vp->type == 'x') || (vp->type == 'X') || (vp->type == 'u'))
		char_count = ft_countnum((unsigned int)(*ld), vp->type);
	if ((vp->precision == 0) && (*ld == 0))
		char_count = 0;
	if (vp->precision > char_count)
		vp->zeropad = vp->precision - char_count;
	if ((ft_readbit(2, &(vp->flags)) == 1) && (*ld != 0))
		vp->width -= 2;
	if ((ft_readbit(3, &(vp->flags)) == 1) && (vp->width > char_count))
	{
		vp->zeropad = vp->width - char_count;
		if ((vp->sign != 0) && (vp->zeropad > 0))
			vp->zeropad--;
	}
	if (vp->width > vp->zeropad + char_count)
		vp->spacepad = vp->width - vp->zeropad - char_count;
	if ((vp->sign != 0) || (ft_readbit (1, &(vp->flags)) == 1))
		vp->spacepad--;
}
