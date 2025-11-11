#include "minishell.h"

typedef enum s_tokentype
{
	T_WORD,    //command or arg
	T_PIPE,    // |
	T_R_IN,    // <
	T_R_OUT,   // >
	T_APPEND,  // >>
	T_HEREDOC, // <<
	T_EOF,
	//bonus
	T_AND, // &&
	T_OR,  // ||
	T_LB,  // (
	T_RB   // )
}						e_tokentype;

typedef struct s_tokenlinkedlist
{
	e_tokentype			type;
	char				*value;
	int					quotetype;
	int 				expand_$_later;
	int					bracket_depth;
	t_tokenlinkedlist	*next;
	t_tokenlinkedlist	*previous;
}						t_tokenlinkedlist;

e_tokentype	assigntokentype(char *word)
{
	if (ft_strlen(word) == 2)
	{
		if (word[0] != word[1])
			return (T_WORD);
		if (word[0] == '>')
			return (T_APPEND);
		else if (word[0] == '<')
			return (T_HEREDOC);
		else if (word[0] == '&')
			return (T_AND);
		else if (word[0] == '|')
			return (T_OR);
		else
			return (T_WORD);
	}
	else if (ft_strlen(word) == 1)
	{
		if (word[0] == '|')
			return (T_PIPE);
		else if (word[0] == '<')
			return (T_R_IN);
		else if (word[0] == '>')
			return (T_R_OUT);
		else if (word[0] == '(')
			return (T_LB);
		else if (word[0] == ')')
			return (T_RB);
		else
			return (T_WORD);
	}
	else
		return (T_WORD);
}

int	expandlatercheck(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

t_tokenlinkedlist	*new_token(char *value, int bracketdepth, int quotetype,
		t_tokenlinkedlist *prev)
{
	t_tokenlinkedlist	*newnode;

	newnode = malloc(sizeof(t_tokenlinkedlist));
	if (!newnode)
		return (NULL);
	newnode->type = assigntokentype(value);
	newnode->bracket_depth = bracketdepth;
	newnode->expand_$_later = expandlatercheck(value);
	newnode->previous = prev;
	newnode->next = NULL;
	newnode->quotetype = quotetype;
	return (newnode);
}
t_tokenlinkedlist	*getlast(t_tokenlinkedlist **head)
{
	while ((*head)->next != NULL)
		(*head) = (*head)->next;
	return (*head);
}

void	add_token(t_tokenlinkedlist **head, t_tokenlinkedlist *new)
{
	while ((*head)->next != NULL)
		(*head) = (*head)->next;
	(*head)->next = new;
	new->previous = (*head);
}

void clearlist(t_tokenlinkedlist **list)
{
	t_tokenlinkedlist	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->value)
			free((*list)->value);
		free(*list);
		* list = tmp;
	}
}

int	h_is_space(char input)
{
	if (input == '\t' || input ==' ')
		return (1);
	else
		return (0);
}

int	h_is_bracket(char input)
{
	if (input == '(' || input ==')')
		return (1);
	else
		return (0);
}
int	h_is_op(char input)
{
	if (input == '|' || input =='<'|| input =='>'|| input =='&')
		return (1);
	else
		return (0);
}
int	h_is_quote(char input)
{
	if (input == '\'')
		return (1);
	else if (input =='\"')
		return (2);
	else
		return (0);
}
int	h_appendchar(char **s, char c)
{
	size_t	len;
	char	*temp;

	if (*s == NULL)
	{
		*s = malloc(2);
		if (!*s)
			return (0);
		(*s)[0] = c;
		(*s)[1] = '\0';
		return (1);
	}
	len = ft_strlen(*s);
	temp = realloc(*s, len + 2);
	if (!temp)
	{
		free(*s);
		*s = NULL;
		return (0);
	}
	*s = temp;
	(*s)[len] = c;
	(*s)[len + 1] = '\0';
	return (1);
}

t_tokenlinkedlist	*parsecmdline(char *cmdline)
{
	int					i;
	int					bracket_depth;
	t_tokenlinkedlist	*list;
	t_tokenlinkedlist	*current;
	char				*val;

	i = 0;
	int quotes; // 0 for not in quotes, 1 for single quote, 2 for double quote
	int	expandlater;
	bracket_depth = 0;
	if (!list)
	{
		//printf error + message
		return (NULL);
	}
	// do malloc check, return if error
	current = NULL;
	list = &current;
	while (cmdline[i] != '\0') // while not end of line
	{
		quotes = 0;
		expandlater = 0;
		val = malloc(ft_strlen(cmdline));
		if (!val)
		{
			clearlist(&list);
			return NULL;
		}
		quotes = h_is_quote(cmdline[i]);
		i += quotes;
		if (cmdline[i] == '(') // handle opening brackets
		{
			add_token(&list, new_token(cmdline[i], bracket_depth, quotes, getlast(&list)));
			bracket_depth++;
			i++;
		}
		if (cmdline[i] == ')') // handle closing brackets
		{
			add_token(&list, new_token(cmdline[i], bracket_depth, quotes, getlast(&list)));
			bracket_depth--;
			i++;
		}
		if (bracket_depth < 0)
		{
			clearlist(&list);
			//print error
			return NULL;
		}
		if (quotes != 0)
		{
			while (quotes != 0)// process as word till quotes == 0 or eof
			{
				if (!cmdline[i])
				{
					clearlist(&list);
					free(val);
					//print error
					return NULL;
				}
				if (cmdline[i] == '$' && quotes == 2)
					expandlater = 1;
				if ((cmdline[i] == 34 && quotes == 2) || (cmdline[i] == 34 && quotes == 1))
					quotes = 0;
				else
				{
					size_t len = ft_strlen(val);
					char *tmp = realloc(val, len + 2);
					if (!tmp)
					{
						clearlist(&list);
						free(val);
						//print error
						return NULL;
					}
					val = tmp;
					val[len] = cmdline[i];
					val[len + 1] = '\0';
				}
				i++;
			}
			add_token(&list, new_token(val, bracket_depth, quotes, getlast(&list)));
			if (expandlater == 1)
			{
				expandlater = 0;
				getlast(&list)->expand_$_later = 1;
			}
			else
				getlast(&list)->expand_$_later = 0;
		}
		// add token with details
		if (cmdline[i] == ' ' || cmdline[i] == '\t') // if it is a whitespace or tab and not in quotes
		{
			//make whitespace/tab type token and add to list
			i++;
		}
		// check if the char is a double operator
		if (cmdline[i] == '|' || cmdline[i] == '&'
				||cmdline[i] == '<' || cmdline[i] == '>')
		{
			ft_bzero(val, ft_strlen(val));
			if (cmdline[i + 1] && cmdline[i] == cmdline[i + 1])
			{
				val = ft_memcpy(val, cmdline[i], 2);
				i += 2;
			}
			else
			{
				val = cmdline[i];
				i ++;
			}
			add_token(&list, new_token(val, bracket_depth, quotes, getlast(&list)));
		}
		else
			// word loop
			int	expandlater;

			while (cmdline[i] != '\0') // while cmdline[i] is not a space, operator, quote, 
			{
				if (cmdline[i] == ' ' || cmdline[i] == '\t'|| cmdline[i] == '<'|| cmdline[i] == '>'|| cmdline[i] == '|'
					|| cmdline[i] == '&' || cmdline[i] == '('|| cmdline[i] == ')'|| cmdline[i] == '\''|| cmdline[i] == '\"')
					break;
	
				char *tmp;
				tmp = cmdline[i];
				val = h_appendchar(&tmp, cmdline[i]);
				if (cmdline[i] == '$')
					expandlater = 1;
				i++;
			}
			add_token(&list, new_token(val, bracket_depth, quotes, getlast(&list)));
			if (expandlater == 1)
			{
				expandlater = 0;
				getlast(&list)->expand_$_later = 1;
			}
			else
				getlast(&list)->expand_$_later = 0;
	}
	if (bracket_depth != 0)
	{
		clearlist(&list);
		//print error
		return NULL;
	}
	// add eof token to end of linked list
	add_token(&list, new_token(val, bracket_depth, quotes, getlast(&list)));
	// return linked list head
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//					Attempt at the tree bit	(pseudocode)				//

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

typedef enum s_treetype
{
	AND,
	OR,
	PIPE,
	CMD,
	SUBSHELL,
}						e_treetype;

typedef struct s_ast_and
{
	//type
}						t_ast_and;

typedef struct s_ast_or
{
	//type
}						t_ast_or;

typedef struct s_ast_pipe
{
	//type
}						t_ast_pipe;

typedef struct s_ast_subshell
{
	//type
}						t_ast_subshell;

typedef struct s_ast_cmd
{
	//type
}						t_ast_cmd;

typedef struct s_ast_tree
{
	int					value;

}						t_ast_tree;

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
	-1 . only 1 child form_tree(rest of stuff goes here to this child).

// run tree...
// L, R, H using dfs... return head