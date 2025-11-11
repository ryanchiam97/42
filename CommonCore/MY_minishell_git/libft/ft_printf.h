/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:15:43 by twtan             #+#    #+#             */
/*   Updated: 2025/05/21 21:18:21 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_strproc
{
	char		flags;
	char		type;
	const char	*tmp_s;
	long		width;
	long		precision;
	int			spacepad;
	int			zeropad;
	char		sign;
	int			valid;
}	t_var;

// File - ft_printf.c
int			ft_printf(const char *str, ...);
//static int			ft_checkstr(const char *str, int *count);
void		ft_reset_vp(t_var *vp);

// File - ft_parser.c
const char	*ft_varformat(const char *s, t_var *vp);
void		ft_showvar_string(char *str, t_var *vp, int *count);
void		ft_showvar_ptr(void *ptr, t_var *vp, int *count);
void		ft_showvar_cdiuxx(long ld, t_var *vp, int *count);
void		ft_show_invalid(t_var *vp, int *count);

// File - ft_prtfunc.c
const char	*ft_txt(const char *str, int *count);
char		*ft_prtstr(char *str, size_t len, int *count);
void		ft_prtchr(char c, int *count);
int			ft_showvar_num(long ld);
int			ft_showvar_hex(size_t ld, char type);

// ft_support.c
int			ft_countnum(long long ld, char type);
const char	*ft_getnum(const char *str, long *rtn);
void		ft_padding(char padchar, int rep, int *count);

// ft_format.c
void		ft_update_var_cdiux(long *ld, t_var *vp);
void		ft_update_var_ptr(void *ptr, t_var *vp);
void		ft_update_var_str(void *str, t_var *vp);
const char	*ft_flag_coder(const char *s, t_var *vp);
void		ft_flags_switcher(t_var *vp);

// ft_flag.c
//void	ft_format_diux(long ld, int *count, t_var *vp);
void		ft_setbit(char bit, char *flag);
void		ft_clearbit(char bit, char *flag);
int			ft_readbit(char bit, char *flag);

#endif
