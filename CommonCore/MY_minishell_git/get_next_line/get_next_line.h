/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:34:03 by twtan             #+#    #+#             */
/*   Updated: 2025/06/22 22:05:53 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct line
{
	char	*lbuf;
	ssize_t	size;
}	t_buf;

// "get_next_line.c" file
char	*get_next_line(int fd);

// "get_next_line_utils.c" file
char	*ft_output_nl(t_buf **lnbuf, ssize_t *status);
char	*ft_output_all(t_buf **lnbuf);
t_buf	*ft_add2buf(t_buf **lnbuf, char *rdbuf, ssize_t *sz);
void	ft_gnl_strcpy(char *dest, char *src, char *tofree, ssize_t sz);
int		ft_nchk(void *addr2check, void *addr2free, ssize_t *rtn);
#endif
