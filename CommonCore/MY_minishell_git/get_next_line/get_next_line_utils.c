/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 22:03:33 by twtan             #+#    #+#             */
/*   Updated: 2025/06/22 22:05:15 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// return a string up to newline if any
char	*ft_output_nl(t_buf **lnbuf, ssize_t *status)
{
	ssize_t	lbi;
	char	*output_str;

	if ((*lnbuf == 0) || (*status < 1))
		return (0);
	if ((*lnbuf)->size < 1)
	{
		free((*lnbuf)->lbuf);
		free(*lnbuf);
		*lnbuf = 0;
		return (0);
	}
	lbi = 0;
	while (((*lnbuf)->lbuf[lbi] != '\n') && (lbi < (*lnbuf)->size - 1))
		lbi++;
	if ((*lnbuf)->lbuf[lbi] != '\n')
		return (0);
	output_str = (char *)malloc(sizeof(char) * (lbi + 2));
	if (ft_nchk(output_str, 0, status) == 0)
		return (0);
	ft_gnl_strcpy(output_str, (*lnbuf)->lbuf, 0, lbi + 1);
	ft_gnl_strcpy((*lnbuf)->lbuf, (*lnbuf)->lbuf + lbi + 1, 0, \
(*lnbuf)->size - lbi - 1);
	(*lnbuf)->size = (*lnbuf)->size - lbi - 1;
	output_str[lbi + 1] = 0;
	return (output_str);
}

char	*ft_output_all(t_buf **lnbuf)
{
	char	*tmp_str;
	ssize_t	sz;

	if (*lnbuf == 0)
		return (0);
	if ((*lnbuf)->size < 1)
	{
		free((*lnbuf)->lbuf);
		free(*lnbuf);
		*lnbuf = 0;
		return (0);
	}
	sz = 1;
	ft_add2buf(lnbuf, "\0", &sz);
	if (sz < 1)
		return (0);
	tmp_str = (*lnbuf)->lbuf;
	free (*lnbuf);
	*lnbuf = 0;
	return (tmp_str);
}

t_buf	*ft_add2buf(t_buf **lnbuf, char *rdbuf, ssize_t *sz)
{
	char	*tmp_str;

	if (*sz < 1)
		return (*lnbuf);
	if (*lnbuf == 0)
	{
		*lnbuf = (t_buf *)malloc(sizeof(t_buf) * 1);
		if (ft_nchk(*lnbuf, 0, sz) == 0)
			return (0);
		(*lnbuf)->lbuf = 0;
		(*lnbuf)->size = 0;
	}
	tmp_str = (char *)malloc(sizeof(char) * (*sz + (*lnbuf)->size));
	if (ft_nchk(tmp_str, *lnbuf, sz) == 0)
	{
		*lnbuf = 0;
		return (0);
	}
	ft_gnl_strcpy(tmp_str, (*lnbuf)->lbuf, (*lnbuf)->lbuf, (*lnbuf)->size);
	(*lnbuf)->lbuf = tmp_str;
	ft_gnl_strcpy((*lnbuf)->lbuf + (*lnbuf)->size, rdbuf, 0, *sz);
	(*lnbuf)->size += *sz;
	return (*lnbuf);
}

void	ft_gnl_strcpy(char *dest, char *src, char *tofree, ssize_t sz)
{
	ssize_t	count;

	if ((src == 0) || (sz < 1))
		return ;
	count = -1;
	while (++count < sz)
		dest[count] = src[count];
	if (tofree != 0)
		free(tofree);
}

int	ft_nchk(void *addr2check, void *addr2free, ssize_t *rtn)
{
	if (addr2check == 0)
	{
		*rtn = -1;
		if (addr2free != 0)
			free(addr2free);
		return (0);
	}
	return (1);
}
