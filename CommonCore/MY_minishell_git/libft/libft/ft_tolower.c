/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:53:58 by twtan             #+#    #+#             */
/*   Updated: 2025/05/06 21:07:57 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// convert uppercase to lowercase
// return the converted case else just return c
int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (c + 32);
	return (c);
}
