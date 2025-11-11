/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_r.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:06:46 by twtan             #+#    #+#             */
/*   Updated: 2025/10/30 21:06:51 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_R_H
# define FT_SPLIT_R_H

# include <stdlib.h>

// ft_split_r.c
int		ft_free_split_arr(char ***arr);
char	**ft_split_r(const char *str, char delimiter);

#endif
