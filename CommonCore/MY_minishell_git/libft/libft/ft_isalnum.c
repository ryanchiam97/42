/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:44:01 by twtan             #+#    #+#             */
/*   Updated: 2025/05/09 21:08:38 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check if c is alphanumeric
// return 0 if not alphanumeric
int	ft_isalnum(int c)
{
	if (c < '0')
		return (0);
	if ((c > '9') && (c < 'A'))
		return (0);
	if ((c > 'Z') && (c < 'a'))
		return (0);
	if (c > 'z')
		return (0);
	return (8);
}
