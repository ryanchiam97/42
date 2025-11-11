/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:22:53 by twtan             #+#    #+#             */
/*   Updated: 2025/05/09 22:15:59 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory for an array of nmemb elements of size bytes
//
// nmemb - number of members
// size - size of a member in bytes
//
// returns a pointer to the allocated memory
// NULL may also be returned by a successful call to calloc() 
// a pointer that can be free when nmemb or size equal to zero
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*mem;
	unsigned int	max;

	if ((nmemb == 0) || (size == 0))
		return (malloc (0));
	max = -1;
	if (max / nmemb < size)
		return (0);
	mem = malloc (nmemb * size);
	if (mem == 0)
		return (0);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
