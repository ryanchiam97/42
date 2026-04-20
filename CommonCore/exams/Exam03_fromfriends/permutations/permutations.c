#include "permutations.h"

long	p_strlen(char *str)
{
	long	count;
	
	count = 0;
	while (str[count] != 0)
		count++;
	return (count);
}

void	p_sort(char *str)
{
	char	tmp;
	long	idx1;
	long	idx2;
	
	idx1 = -1;
	while (str[++idx1] != 0)
	{
		idx2 = idx1;
		while (str[++idx2] != 0)
		{
			if (str[idx1] > str[idx2])
			{
				tmp = str[idx1];
				str[idx1] = str[idx2];
				str[idx2] = tmp;
			}
		}
	}
}

int	p_search(char *str, int *use, int *seq, int s)
{
	int	idx;
	
	// last stage
	if (str[s] == 0)
	{
		// print sequence
		idx = -1;
		while (str[++idx] != 0)
			write(1, &(str[seq[idx] - 1]), 1);
		write (1, "\n", 1);
		return (RTN_OK);
	}
	
	// search
	idx = -1;
	while (1)
	{
		if (seq[s] != 0)
			p_search(str, use, seq, s + 1);
		
		// selection condition
		
		// deselect
		if (seq[s] != 0)
		{
			use[seq[s] - 1] = 0;
			seq[s] = 0;
		}
		
		// new selection	
		idx++;
		while ((str[idx] != 0) && (use[idx] != 0))
			idx++;
		if (str[idx] == 0)
			return (RTN_OK);
		if (use[idx] == 0)
		{
			seq[s] = idx + 1;
			use[idx] = 1;
		}
	}
	return (RTN_OK);
}

int	main(int argc, char **argv)
{
	int	*seq;
	int	*use;
	long	len;
	
	// check argument - must be 2 and must not be empty
	if (argc != 2)
		return (RTN_ERR);
	if (argv[1][0] == 0)
		return (RTN_ERR);

	// setup params
	len = p_strlen(argv[1]);
	seq = (int *)calloc(sizeof(int), len);
	if (seq == 0)
		return (RTN_ERR);
	use = (int *)calloc(sizeof(int), len);
	if (seq == 0)
	{
		free (seq);
		return (RTN_ERR);
	}
	
	//pre-sort string
	p_sort(argv[1]);
	
	p_search(argv[1], use, seq, 0);
	
	free (seq);
	free (use);
		
	return (RTN_OK);
}
