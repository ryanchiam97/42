/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:12:31 by twtan             #+#    #+#             */
/*   Updated: 2025/06/03 19:15:03 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// Supporting function
// Set the bit in the flag, if already set previously set bit 7 too
// bit - bit position, 0 to 7
void	ft_setbit(char bit, char *flag)
{
	char	bitpos;

	if ((bit < 0) || (bit > 7))
		return ;
	bitpos = 1;
	bitpos = bitpos << bit;
	if ((*flag & bitpos) > 0)
		*flag |= 128;
	*flag |= bitpos;
}

// Supporting function
// Clear the bit in the flag
// bit - bit position, 0 to 7
void	ft_clearbit(char bit, char *flag)
{
	char	bitpos;

	if ((bit < 0) || (bit > 7))
		return ;
	bitpos = 1;
	bitpos = bitpos << bit;
	*flag &= ~bitpos;
}

// Supporting function
// read the bit in the flag
// bit - bit position, 0 to 7
// returns 1 if bit is set, 0 if bit is clear, -1 if there is error
int	ft_readbit(char bit, char *flag)
{
	char	bitpos;

	if ((bit < 0) || (bit > 7))
		return (-1);
	bitpos = 1;
	bitpos = bitpos << bit;
	if ((*flag & bitpos) > 0)
		return (1);
	else
		return (0);
}

const char	*ft_flag_coder(const char *s, t_var *vp)
{
	while ((ft_strchr("-0# +", *s) != 0) && (*s != 0))
	{
		if (*s == '-')
			ft_setbit (4, &(vp->flags));
		if (*s == '0')
			ft_setbit (3, &(vp->flags));
		if (*s == '#')
			ft_setbit (2, &(vp->flags));
		if (*s == ' ')
			ft_setbit (1, &(vp->flags));
		if (*s == '+')
			ft_setbit (0, &(vp->flags));
		s++;
	}
	return (s);
}
