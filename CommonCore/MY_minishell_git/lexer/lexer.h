/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:32:39 by rchiam            #+#    #+#             */
/*   Updated: 2025/11/20 22:27:19 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../libft/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

typedef enum s_tokentype
{
	T_WORD,    //command or arg
	T_PIPE,    // |
	T_R_IN,    // <
	T_R_OUT,   // >
	T_APPEND,  // >>
	T_HEREDOC, // <<
	T_EOF,
	T_AND,  // &&
	T_OR,   // ||
	T_LB,   // (
	T_RB,   // )
	T_ERROR // not sure if will do...
}								t_tokentype;

typedef struct s_tokenlinkedlist
{
	t_tokentype					type;
	char						*value;
	int							quotetype;
	int							expand_later;
	int							bracket_depth;
	int							is_heredoc_delim;
	int							has_space_before;
	struct s_tokenlinkedlist	*next;
	struct s_tokenlinkedlist	*previous;
}								t_tokenlinkedlist;

typedef struct s_lexer_params
{
	char						*cmdline;
	int							i;
	int							bracketdepth;
	int							parsed_chars;
	t_tokenlinkedlist			*head;
	t_tokenlinkedlist			*current;
}								t_lexer_params;

t_tokenlinkedlist	*tl_make_new_token(char *value, int bracketdepth,
		int quotetype, t_tokenlinkedlist *prev);

t_tokentype						tl_assign_token_type0(char *word);
t_tokentype						tl_assign_token_type1(char *word);
t_tokentype						tl_assign_token_type2(char *word);

int								tl_check_expansion(char *value);

void	tl_add_token(t_tokenlinkedlist **head,
					t_tokenlinkedlist *newtoken);

t_tokenlinkedlist				*tl_get_first(t_tokenlinkedlist *node);
t_tokenlinkedlist				*tl_get_last(t_tokenlinkedlist *head);

void							tl_clear_list(t_tokenlinkedlist *list);

int								i_is_space(char input);
int								i_is_bracket(char input);
int								i_is_op(char input);
int								i_is_quote(char input);

t_tokenlinkedlist				*h_handle_quote(t_lexer_params *lp);
t_tokenlinkedlist				*h_handle_bracket(t_lexer_params *lp);
t_tokenlinkedlist				*h_handle_operator(t_lexer_params *lp);
t_tokenlinkedlist				*h_handle_word(t_lexer_params *lp);
t_tokenlinkedlist				*h_handle_eof(t_lexer_params *lp);

void							h_handle_space(t_lexer_params *lp);

t_lexer_params					*lp_init_lexer_params(char *cmdline);
void							lp_clear_lexer_params(t_lexer_params *lp);

t_tokenlinkedlist				*lp_parsecmdline0(char *cmdline);

#endif