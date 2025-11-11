/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:00:11 by twtan             #+#    #+#             */
/*   Updated: 2025/05/09 23:08:10 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descriptions
Applies the function ’f’ to each character of the string passed as argument,
passing its index as the first argument. Each character is passed by address 
to ’f’ so it can be modified if necessary.

Arguments
s: The string to iterate over.
f: The function to apply to each character.

*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if ((s == 0) || (f == 0))
		return ;
	i = 0;
	while (s[i] != 0)
	{
		f(i, s + i);
		i++;
	}
}
