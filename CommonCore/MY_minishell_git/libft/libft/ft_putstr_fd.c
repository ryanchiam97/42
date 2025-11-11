/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:14:23 by twtan             #+#    #+#             */
/*   Updated: 2025/05/09 23:17:09 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

Descriptions
Outputs the string ’s’ to the specified file descriptor.

*/

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (fd < 0)
		return ;
	len = ft_strlen(s);
	write (fd, s, len);
}
