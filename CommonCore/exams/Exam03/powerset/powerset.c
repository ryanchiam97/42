#include "powerset.h"

void	ps_prt(int *set, int *use, int set_len)
{
	int	idx;
	
	// print first number
	idx = 0;
	while ((use[idx] == 0) && (idx < set_len))
		idx++;
	if (idx == set_len)
		return ;
	printf("%d", set[idx]);
	
	// print next few number if available - with space
	while (++idx < set_len)
	{
		if (use[idx] == 1)
			printf(" %d", set[idx]);
	}
	printf("\n");
}

int	ps_sum(int *set, int *use, int set_len)
{
	int	idx;
	int	sum;
	
	idx = -1;
	sum = 0;
	while (++idx < set_len)
	{
		if (use[idx] == 1)
			sum += set[idx];
	}
	return (sum);
}

int	ps_search(int *set, int *use, int set_len, int n, int s)
{
	// last stage - check solution
	if (set_len == s)
	{
		if (ps_sum(set, use, set_len) == n)
			ps_prt(set, use, set_len);
		return (1);
	}
	
	// search
	while (1)
	{
		// next stage
		ps_search(set, use, set_len, n, s + 1);
		
		// condition check
		if (use[s] == 1)
		{
			use[s] = 0;
			return (1);
		}
		if (use[s] == 0)
			use[s] = 1;
	}
	
	return (1);
}

int	main(int argc, char **argv)
{
	int	*set;
	int	*use;
	int	n;
	int	set_len;
	int	idx;
	
	// check for right amount of argument
	if (argc < 2)
		return (RTN_ERR);

	// convert argument for n into int
	n = atoi(argv[1]);
	
	// print empty set
	if (n == 0)
		printf("\n");
	
	// convert argument for set into int
	set_len = argc - 2;
	
	// no set - no solution
	if (set_len == 0)
		return (RTN_ERR);

	set = (int *)malloc(sizeof(int) * (set_len));
	if (set == 0)
		return (RTN_ERR);

	use = (int *)calloc(sizeof(int), set_len);
	if (use == 0)
		return (RTN_ERR);
		
	idx = -1;
	while (++idx < argc - 2)
		set[idx] = atoi(argv[idx + 2]);
		
	ps_search(set, use, set_len, n, 0);
	
	free (use);
	free (set);
	
	return (RTN_OK);
}
