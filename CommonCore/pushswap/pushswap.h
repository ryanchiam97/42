/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:44:06 by rchiam            #+#    #+#             */
/*   Updated: 2025/09/18 00:18:06 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_stack	t_stack;

typedef void			(*t_op)(t_stack *);
typedef void			(*t_op2)(t_stack *, t_stack *);

struct s_stack
{
	int					*arr;
	int					size;
	char				name;
	struct s_stack		*other;
	t_op				swap;
	t_op				rotate;
	t_op				revrotate;
	t_op2				push_to_other;
	t_op2				push_to_self;
	// int					max;
	// int					min;
	// int					maxindex;
	// int					minindex;
};

// int 					imin(int a, int b);
// int 					isqrt(int n);
// void    				updateminmax(t_stack *s);
// void    				updateminmaxzero(t_stack *s);
int						get_char_arr_size(char **arr);
int						*parseinput(char *input, int *returnsize);
void					index_arr(int **int_arr, int size);
int						determinepower(int max);
int						checkdupes(int *int_arr, int size);

int						check_string(char *str);
char					*safeaddstring(char *main, char *new);
int						parse(int argcount, char ***args, int **return_array);
int						parse_int_arr(char **str, int *sizeadr, int ***r_arr);

t_stack					*initstack(int *arr, char name, int size, int maxsize);
void					assign_ops(t_stack *s);
void					loadotherstack(t_stack *s, t_stack *other);
void					freeallstacksandinput(t_stack *a, t_stack *b, int *intarr);
t_stack					*stack_startup(int *arr, int max_size);

int						push(t_stack *src, t_stack *dst);
void					pa(t_stack *a, t_stack *b);
void					pb(t_stack *a, t_stack *b);

int						swap(t_stack *s);
void					sa(t_stack *a);
void					sb(t_stack *b);
void					ss(t_stack *a, t_stack *b);

void					rotate(t_stack *s);
void					ra(t_stack *a);
void					rb(t_stack *b);
void					rr(t_stack *a, t_stack *b);

void					revrotate(t_stack *s);
void					rra(t_stack *a);
void					rrb(t_stack *b);
void					rrr(t_stack *a, t_stack *b);

void					sorttwo(t_stack *s);
void					sortthree(t_stack *s);

int						find_smallest_index(t_stack *s);
void					pushsmallest(t_stack *s, int smallestindex);
void					sortfourfive(t_stack *s);

void					globalradixsort(t_stack *s, int totalbinarydigits);
// int						pushback(t_stack *s);
// void					chunkdecisionlayer(t_stack *s);

// void	pushover(t_stack *s, int pushbit, int rot, int power);
// int	getrotation(t_stack *s, int p);
// int						get_rotations(t_stack *s, int power);
// int						determinerotation(t_stack *s, int bit, int power);
// void printout_stack_info(t_stack *s);

#endif
