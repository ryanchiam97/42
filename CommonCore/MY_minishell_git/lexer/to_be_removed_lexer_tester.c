#include "lexer.h"

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
			"Has_Space_Before '%i'\n"
			"Previous '%p'\n"
			"Next '%p'\n"
			"=======================\n",
			t->value,
			t->quotetype,
			t->bracket_depth,
			t->expand_later,
			t->is_heredoc_delim,
			t->has_space_before,
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
	printf("%-4s %-8s %-40s %-5s %-7s %-7s %-7s %-7s %-14s %-14s\n",
		"#", "TYPE", "VALUE", "Q", "BRACK", "EXP", "HD", "SpaceBef","PREV", "NEXT");
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

		printf("%-4d %-8s %-40.40s %-5d %-7d %-7d %-7d %-7d %-14p %-14p\n",
			count,
			type,
			val,
			t->quotetype,
			t->bracket_depth,
			t->expand_later,
			t->is_heredoc_delim,
			t->has_space_before,
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
	// cc -g to_be_removed_lexer_tester.c ../libft/libftprintf.a ../libft/libft/libft.a
	// have an input.txt file to write in test input
	// ./a.out "$(cat input.txt)"
	printf("cmdline input: %s\n", argv[1]);
	printf("\n");
	print_tester(lp_parsecmdline(argv[1]));
	printf("\n");
	printf("chart:\n");
	gpt_print_tester(lp_parsecmdline(argv[1]));
	printf("\n");
	printf("in-line view:\n");
	gpt_print_values_inline(lp_parsecmdline(argv[1]));
}
