#include "rip.h"

long	rip_count_c (char *str, char c)
{
	long	count;
	
	count = 0;
	while (*str != 0)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	rip_check(char *str)
{
	long	idx;
	long	bal;
	
	bal = 0;
	idx = -1;
	while (str[++idx] != 0)
	{
		if (str[idx] == '(')
			bal++;
		if (str[idx] == ')')
			bal--;
		if (bal < 0)
			return (RTN_ERR);
	}
	if (bal != 0)
		return (RTN_ERR);
	return (RTN_OK);
}

int	rip_search (char *str, int bal, int *min, int s)
{
	char	tmp;
	
	// last stage
	if (str[s] == 0)
	{
		if (rip_check(str) == RTN_OK)
		{
			if (*min == -1)
				*min = rip_count_c (str, ' ');
			if (*min == rip_count_c (str, ' '))
				puts(str);
		}
		return (1);
	}
	
	// prestore
	tmp = str[s];
	
	// precheck and selection
	if (str[s] == '(')
		bal++;
	if (str[s] == ')')
		bal--;
	if (bal < 0)
	{
		str[s] = ' ';
		bal++;
	}
	// search
	while (1)
	{
		// next stage
		rip_search (str, bal, min, s + 1);
		
		// condition check
		if (str[s] == ' ')
		{
			str[s] = tmp;
			return (1);
		}
		if (str[s] != ' ')
		{
			if (str[s] == '(')
				bal--;
			if (str[s] == ')')
				bal++;
			str[s] = ' ';
		}
	}
	
}

int	main (int argc, char **argv)
{
	int	min;

	if (argc != 2)
		return (RTN_ERR);
		
	if (argv[1] == 0)
		return (RTN_ERR);
	
	//precheck
	if (rip_check(argv[1]) == RTN_OK)
	{
		puts(argv[1]);
		return (RTN_OK);
	}
	
	min = -1;
	rip_search (argv[1], 0, &min, 0);
	
	return (RTN_OK);
}
