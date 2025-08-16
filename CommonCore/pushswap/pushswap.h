/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:44:06 by rchiam            #+#    #+#             */
/*   Updated: 2025/08/16 15:50:25 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef void		(*t_op)(t_stack *);
typedef void		(*t_op2)(t_stack *, t_stack *);

typedef struct s_stack
{
	int				*arr;
	int				size;
	char			name;
	struct s_stack	*other;
	t_op			swap;
	t_op			rotate;
	t_op			revrotate;
	t_op2			push_to_other;
	t_op2			push_to_self;
}					t_stack;

int					get_char_arr_size(char **arr);
int					*parseinput(char *input);
void				index(int **int_arr, int size);
int					determinepower(int max);

int					check_string(char *str);
char				*addstring(char *main, char *new);
int					checkdupes(int *int_arr, int size);

int					push(t_stack *src, t_stack *dst);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

int					swap(t_stack *s);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

void				rotate(t_stack *s);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

void				revrotate(t_stack *s);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

void				sortthree(t_stack *s);
void				sortthreelogic(t_stack *s, t_op swp, t_op rt, t_op revrt);

#endif
