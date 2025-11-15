//#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include "libft/ft_printf.h"
#include "ft_split_r/ft_split_r.h"
#include "ft_readline/ft_readline.h"
#include <readline/readline.h>	// readline
#include <readline/history.h>	// rl_clear_history
#include <curses.h>		// tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
#include <term.h>
#include <termios.h>
#include <signal.h>

typedef enum s_tokentype
{
	T_WORD,//command or arg
	T_PIPE,// |
	T_R_IN,// <
	T_R_OUT,// >
	T_APPEND,// >>
	T_HEREDOC,// <<
	T_EOF,
	T_AND,// &&
	T_OR,// ||
	T_LB,// (
	T_RB// )
}	t_tokentype;

typedef struct s_tokenlinkedlist
{
	t_tokentype					type;
	char						*value;
	int							quotetype;
	int							expand_later;
	int							bracket_depth;
	int							is_heredoc_delim;
	struct s_tokenlinkedlist	*next;
	struct s_tokenlinkedlist	*previous;
}	t_tokenlinkedlist;

typedef struct s_lexer_params
{
	char*				cmdline;
	int					i;
	int					bracketdepth;
	int					parsed_chars;
	t_tokenlinkedlist	*head;
	t_tokenlinkedlist	*current;
}	t_lexer_params;

t_tokentype	tl_assign_token_type2(char *word)
{
	char	c1;
	char	c2;

	c1 = word[0];
	c2 = word[1];
	if (c1 != c2)
		return (T_WORD);
	if (c1 == '>')
		return (T_APPEND);
	else if (c1 == '<')
		return (T_HEREDOC);
	else if (c1 == '&')
		return (T_AND);
	else if (c1 == '|')
		return (T_OR);
	else
		return (T_WORD);
}
t_tokentype	tl_assign_token_type1(char *word)
{
	char	c1;

	c1 = word[0];
	if (c1 == '|')
		return (T_PIPE);
	else if (c1 == '<')
		return (T_R_IN);
	else if (c1 == '>')
		return (T_R_OUT);
	else if (c1 == '(')
		return (T_LB);
	else if (c1 == ')')
		return (T_RB);
	else if (c1 == '\0')
		return (T_EOF);
	else
		return (T_WORD);
}
t_tokentype	tl_assign_token_type0(char *word)
{
	int	len;

	len = ft_strlen(word);
	if (len == 2)
		return(tl_assign_token_type2(word));
	else if (len == 1)
		return(tl_assign_token_type1(word));
	else
		return (T_WORD);
}

int	tl_check_expansion(char *value)
{
	int	i;
	int	expansion;

	i = 0;
	expansion = 0;
	while (value[i])
	{
		if (value[i] == '$' || value[i] == '*')
			expansion = 1;
		i++;
	}
	return (expansion);
}

t_tokenlinkedlist	*tl_make_new_token(char *value, int bracketdepth,
		int quotetype, t_tokenlinkedlist *prev)
{
	t_tokenlinkedlist	*newnode;

	newnode = malloc(sizeof(t_tokenlinkedlist));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->type = tl_assign_token_type0(value);
	newnode->bracket_depth = bracketdepth;
	newnode->quotetype = quotetype;
	if (!prev)
		newnode->previous = NULL;
	else
		newnode->previous = prev;
	newnode->next = NULL;
	if (prev && prev->type == T_HEREDOC)
		newnode->is_heredoc_delim = 1;
	else
		newnode->is_heredoc_delim = 0;
	if (newnode->type == T_WORD && newnode->quotetype != 1
		&& newnode->is_heredoc_delim == 0)
		newnode->expand_later = tl_check_expansion(value);
	else
		newnode->expand_later = 0;
	return (newnode);
}
t_tokenlinkedlist	*tl_get_last(t_tokenlinkedlist *head)
{
	if (!head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

t_tokenlinkedlist	*tl_get_first(t_tokenlinkedlist *node)
{
	if (!node)
		return (NULL);
	while (node->previous != NULL)
		node = node->previous;
	return (node);
}

void	tl_add_token(t_tokenlinkedlist **head, t_tokenlinkedlist *new)
{
	t_tokenlinkedlist	*last;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	last = tl_get_last(*head);
	last->next = new;
	new->previous = last;
	return ;
}

void	tl_clear_list(t_tokenlinkedlist *list)
{
	t_tokenlinkedlist	*tmp;

	while (list)
	{
		tmp = list->next;
		if (list->value)
			free(list->value);
		free(list);
		list = tmp;
	}
}

int	i_is_space(char input)
{
	if (input == '\t' || input == ' ')
		return (1);
	else
		return (0);
}

int	i_is_bracket(char input)
{
	if (input == '(' || input == ')')
		return (1);
	else
		return (0);
}
int	i_is_op(char input)
{
	if (input == '|' || input == '<' || input == '>' || input == '&')
		return (1);
	else
		return (0);
}
int	i_is_quote(char input)
{
	if (input == '\'')
		return (1);
	else if (input == '\"')
		return (2);
	else
		return (0);
}
t_tokenlinkedlist	*h_handle_quote_token(t_lexer_params *lp)
{
	int					quote;
	char				*value;
	int					j;
	int					quote_closed;
	t_tokenlinkedlist	*new;

	value = NULL;
	quote = i_is_quote(lp->cmdline[lp->i]);
	j = 1;
	quote_closed = 0;
	while (lp->cmdline[lp->i + j] != '\0')
	{
		if (quote == i_is_quote(lp->cmdline[lp->i + j]))
		{
			quote_closed = 1;
			break ;
		}
		j++;
	}
	if (lp->cmdline[lp->i + j] == '\0' && quote_closed == 0)
		return (NULL);
	value = malloc(sizeof(char) * j);
	if (!value)
		return (NULL);
	ft_strlcpy(value, &lp->cmdline[lp->i + 1], j);
	new = tl_make_new_token(value, lp->bracketdepth, quote, lp->current);
	if (!new)
		return (NULL);
	lp->parsed_chars = j + 1;
	return (new);
}

t_tokenlinkedlist	*h_handle_bracket(t_lexer_params *lp)
{
	t_tokenlinkedlist	*new;

	if (lp->cmdline[lp->i] == '(')
	{
		(lp->bracketdepth)++;
		new = tl_make_new_token("(", lp->bracketdepth, 0, lp->current);
	}
	else if (lp->cmdline[lp->i] == ')')
	{
		new = tl_make_new_token(")", lp->bracketdepth, 0, lp->current);
		(lp->bracketdepth)--;
	}
	lp->parsed_chars = 1;
	return (new);
}
t_tokenlinkedlist	*h_handle_operator(t_lexer_params *lp)
{
	char				*value;
	t_tokenlinkedlist	*new;

	value = malloc(3 * sizeof(char));
	if (!value)
		return (NULL);
	value[0] = lp->cmdline[lp->i];
	value[2] = '\0';
	if (lp->cmdline[lp->i + 1]
		&& (lp->cmdline[lp->i] == lp->cmdline[lp->i + 1]))
	{
		value[1] = value[0];
		lp->parsed_chars = 2;
	}
	else
	{
		value[1] = '\0';
		lp->parsed_chars = 1;
	}
	new = tl_make_new_token(value, lp->bracketdepth, 0, lp->current);
	return (new);
}
void	h_handle_space(t_lexer_params *lp)
{
	int	count;

	count = 0;
	while (i_is_space(lp->cmdline[lp->i + count]))
		count++;
	lp->parsed_chars = count;
}
t_tokenlinkedlist	*h_handle_word(t_lexer_params *lp)
{
	int					j;
	char				*value;
	int					expand;
	t_tokenlinkedlist	*new;

	j = 0;
	while (lp->cmdline[lp->i + j] != '\0'
		&& !i_is_space(lp->cmdline[lp->i + j])
		&& !i_is_quote(lp->cmdline[lp->i + j])
		&& !i_is_bracket(lp->cmdline[lp->i + j])
		&& !i_is_op(lp->cmdline[lp->i + j]))
		j++;
	value = malloc(sizeof(char) * (j + 1));
	if (!value)
		return (NULL);
	ft_strlcpy(value, &lp->cmdline[lp->i], j + 1);
	new = tl_make_new_token(value, lp->bracketdepth, 0, lp->current);
	if (!new)
		return (NULL);
	lp->parsed_chars = j;
	return (new);
}
t_tokenlinkedlist	*p_handle_eof(t_lexer_params *lp)
{
	t_tokenlinkedlist *new;

	if (lp->bracketdepth != 0)
		return (NULL);
	new = malloc(sizeof(t_tokenlinkedlist));
	if (!new)
		return (NULL);
	new->bracket_depth = 0;
	new->expand_later = 0;
	new->is_heredoc_delim = 0;
	new->next = NULL;
	new->previous = lp->current;
	new->quotetype = 0;
	new->type = T_EOF;
	new->value = "EOF";
	return(new);
}

t_lexer_params	*p_init_lexer_params(char *cmdline)
{
	t_lexer_params*	l_params;

	l_params = malloc(sizeof(t_lexer_params));
	if (!l_params)
		return (NULL);
	l_params->cmdline = ft_strdup(cmdline);
	if (!l_params->cmdline)
	{
		free(l_params);
		return (NULL);
	}
	l_params->i = 0;
	l_params->bracketdepth = 0;
	l_params->parsed_chars = 0;
	l_params->head = NULL;
	l_params->current = NULL;
	return (l_params);
}
void	p_clear_lexer_params(t_lexer_params *lp)
{
	free(lp->cmdline);
	free(lp);
}

t_tokenlinkedlist	*parsecmdline(char *cmdline)
{
	t_lexer_params		*lp;
	t_tokenlinkedlist	*new;
	t_tokenlinkedlist	*list;
	int					space;

	lp = p_init_lexer_params(cmdline);
	if (!lp)
		return (NULL);
	while (lp->cmdline[lp->i] != '\0')
	{
		lp->parsed_chars = 0;
		space = 0;
		new = NULL;
		if (i_is_quote(lp->cmdline[lp->i]))
			new = (h_handle_quote_token(lp));
		else if (i_is_bracket(lp->cmdline[lp->i]))
			new = (h_handle_bracket(lp));
		else if (i_is_op(lp->cmdline[lp->i]))
			new = (h_handle_operator(lp));
		else if (i_is_space(lp->cmdline[lp->i]))
		{
			h_handle_space(lp);
			space = 1;
		}
		else
			new = h_handle_word(lp);
		if (!new && space == 0)
			return (tl_clear_list(lp->head), p_clear_lexer_params(lp), NULL);
		tl_add_token(&lp->head, new);
		lp->i += lp->parsed_chars;
		lp->current = tl_get_last(lp->head);
	}
	new = p_handle_eof(lp);
	tl_add_token(&lp->head, new);
	list = lp->head;
	p_clear_lexer_params(lp);
	return (list);
}

/*logic/flow
- init parameters
- go through cmdline till eof making new tokens per char block
	- if in quotes, till you see a matching quote just keep adding to word. note quote type
	- if brackets, increase or decrease bracket depth
	- if operator, handle single vs double
	- if space, keep adding to i till hitting new word char
	- else handle word
- clear params, return list of tokens
*/

void	print_tester(t_tokenlinkedlist *t)
{
	int	id = 1;
	int	count = 0;

	printf("\n===========Lexer Results============\n");
	while (t)
	{
		count+= 1;
		printf("Token %i\n", count);
		char *type = "";
		if (t->type == T_AND)
			type = "AND";
		else if (t->type == T_APPEND)
			type = "APPEND";
		else if (t->type == T_EOF)
			type = "EOF";
		else if (t->type == T_HEREDOC)
			type = "HEREDOC";
		else if (t->type == T_LB)
			type = "LB";
		else if (t->type == T_OR)
			type = "OR";
		else if (t->type == T_PIPE)
			type = "PIPE";
		else if (t->type == T_R_IN)
			type = "R_IN";
		else if (t->type == T_R_OUT)
			type = "R_OUT";
		else if (t->type == T_RB)
			type = "RB";
		else if (t->type == T_WORD)
			type = "WORD";
		printf("Type '%s'\n", type);
		printf(
			"Value '%s'\n"
			"Quote '%i'\n"
			"Bracket '%i'\n"
			"Expand '%i'\n"
			"Heredoc '%i'\n"
			"Previous '%p'\n"
			"Next '%p'\n"
			"=======================\n",
			t->value,
			t->quotetype,
			t->bracket_depth,
			t->expand_later,
			t->is_heredoc_delim,
			(void *) t->previous,
			(void *) t->next);
		t = t->next;
	}
	printf("token count: %i\n", count);
}

void	gpt_print_tester(t_tokenlinkedlist *t)
{
	int		count;
	char	*type;
	char	*val;

	count = 0;
	printf("\n=========== Lexer Results ===========\n");
	printf("%-4s %-8s %-40s %-5s %-7s %-7s %-7s %-14s %-14s\n",
		"#", "TYPE", "VALUE", "Q", "BRACK", "EXP", "HD", "PREV", "NEXT");
	printf("------------------------------------------------------------------------------------------\n");
	while (t)
	{
		count++;
		type = "UNK";
		if (t->type == T_AND)
			type = "AND";
		else if (t->type == T_APPEND)
			type = "APPEND";
		else if (t->type == T_EOF)
			type = "EOF";
		else if (t->type == T_HEREDOC)
			type = "HEREDOC";
		else if (t->type == T_LB)
			type = "LB";
		else if (t->type == T_OR)
			type = "OR";
		else if (t->type == T_PIPE)
			type = "PIPE";
		else if (t->type == T_R_IN)
			type = "R_IN";
		else if (t->type == T_R_OUT)
			type = "R_OUT";
		else if (t->type == T_RB)
			type = "RB";
		else if (t->type == T_WORD)
			type = "WORD";

		val = t->value ? t->value : "(null)";

		printf("%-4d %-8s %-40.40s %-5d %-7d %-7d %-7d %-14p %-14p\n",
			count,
			type,
			val,
			t->quotetype,
			t->bracket_depth,
			t->expand_later,
			t->is_heredoc_delim,
			(void *)t->previous,
			(void *)t->next);
		t = t->next;
	}
	printf("------------------------------------------------------------------------------------------\n");
	printf("Token count: %d\n", count);
}

char *gpt_escape_value(const char *s)
{
    int i = 0, j = 0;
    char *out;

    if (!s)
        return strdup("(null)");

    // worst case: every char becomes 2 chars (e.g. \n => "\\n")
    out = malloc(ft_strlen(s) * 2 + 1);
    if (!out)
        return strdup("(allocfail)");

    while (s[i])
    {
        if (s[i] == '\n')
        {
            out[j++] = '\\';
            out[j++] = 'n';
        }
        else if (s[i] == '\t')
        {
            out[j++] = '\\';
            out[j++] = 't';
        }
        else if (s[i] == '\r')
        {
            out[j++] = '\\';
            out[j++] = 'r';
        }
        else if ((unsigned char)s[i] < 32)   // control chars
        {
            j += sprintf(&out[j], "\\x%02X", (unsigned char)s[i]);
        }
        else
        {
            out[j++] = s[i];
        }
        i++;
    }
    out[j] = '\0';
    return out;
}


void	gpt_print_values_inline(t_tokenlinkedlist *t)
{
	char *val;

	printf("Values: ");
	while (t)
	{
		val = gpt_escape_value(t->value);  // reuse the escape helper
		printf("[%s]", val);
		free(val);
		t = t->next;
	}
	printf("\n");
}


int main(int argc, char **argv)
{
	// do make in the libft and printflibft dirs
	// cc -g experiment_on_lex.c libft/libftprintf.a libft/libft/libft.a
	printf("%s\n", argv[1]);
	//print_tester(parsecmdline(argv[1]));
	gpt_print_tester(parsecmdline(argv[1]));
	gpt_print_values_inline(parsecmdline(argv[1]));
}

//////////////////////////////////////////////////////////////////////////

//					Attempt at the tree bit	(pseudocode)				//

//////////////////////////////////////////////////////////////////////////

// Reverse Polish Notation

// Shunting yard

typedef enum s_treetype
{
	AND,
	OR,
	PIPE,
	CMD,
	SUBSHELL,
}								e_treetype;

typedef struct s_ast_and
{
	//type
}								t_ast_and;

typedef struct s_ast_or
{
	//type
}								t_ast_or;

typedef struct s_ast_pipe
{
	//type
}								t_ast_pipe;

typedef struct s_ast_subshell
{
	//type
}								t_ast_subshell;

typedef struct s_ast_cmd
{
	//type
}								t_ast_cmd;

typedef struct s_ast_tree
{
	int							value;

}								t_ast_tree;

//t_ast_tree *form_tree(*tokenlinkedlist cmdlist)
// while still got stuff in node_linked_list
// move down linked list L to R
// check for bracket depth lowest range... equal to current... ignore all in diff subshell/ deeper depth
// look for and pick logical operation (&& or ||)... set as root
// left child: all on left & in same bracket depth... form_tree(start of range to right before)
// right child: all on right & in same bracket depth... form_tree(right after operation to end of range)
// look for and pick pipe and equal depth range
// left child: all on left & in same bracket depth... form_tree(start of range to right before)
// right child: all on right & in same bracket depth... form_tree(right after operation to end of range)
// look for and pick command and equal depth range
// left child: parse word to cmd, args, options etc
// right child: parse word to cmd, ""
// return
// look for and pick subshell and equal depth range
// rm brackets, current depth
//	-1 . only 1 child form_tree(rest of stuff goes here to this child).

// run tree...
// L, R, H using dfs... return head