#include "n_queens.h"

void	nq_display_sol(int *col, int n)
{
	int	count;

	count = -1;
	while (++count < n - 1)
		fprintf(stdout, "%d ", col[count]);
	fprintf(stdout, "%d\n", col[count]);
}

// return -1 if invalid pos
int	nq_valid_pos(int *col, int n)
{
	int idx1;
	int idx2;
	
	idx1 = -1;
	while (++idx1 < n)
	{
		idx2 = idx1;
		while (++idx2 < n)
		{
			// same number check
			if (col[idx1] == col[idx2])
				return (-1);
			// left diagonal
			if (col[idx1] == col[idx2] - (idx2 - idx1))
				return (-1);
			// right diagonal
			if (col[idx1] == col[idx2] + (idx2 - idx1))
				return (-1);
		}
	}
	return (0);
}

// return
// 0 : valid selection
// 1 : deselect previous stage
// 2 : invalid selection

int	nq_next_pos (int *col, int *row, int s, int n)
{
	int	r_idx;
	int	result;

	// last stage - check for valid number selection
	if (s == n)
	{
		if (nq_valid_pos(col, n) == 0)
		{
			nq_display_sol(col, n);
			return (1);
		}
		return(2);
	}
	
	// setup
	r_idx = 0;
	result = 2;
	
	// step though selection
	while (result != 0)
	{	
		// check available number for selection
		while ((r_idx < n) && (row[r_idx] != 0))
			r_idx++;
		if (r_idx == n)
			return (1);

		// select position in this colume
		col[s] = r_idx;
		row[r_idx] = 1;
		
		// recursive call next stage (column)
		result = nq_next_pos(col, row, s + 1, n);
		
		// invalid number - forword selection
		if (result != 0)
		{
			row[r_idx] = 0;
			r_idx++;
			if (r_idx >= n)
				return (1);
		}
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	n;
	int	count;
	int	*col;
	int	*sel;
	
	// check for the number of argument
	if (argc != 2)
		return (0);
	
	// convert the input argument
	n = atoi(argv[1]);
	if ((n < 0) || (n > MAX_SIZE))
		return (1);
	
	// no solution for 3 or lesser columns
	if (n <= 3)
		return (1);
	
	// setup parameters
	sel = (int*)malloc(sizeof(int) * n);
	if (sel == 0)
		return (1);
	col = (int*)malloc(sizeof(int) * n);
	if (col == 0)
	{
		free (sel);
		return (1);
	}
	
	count = -1;
	while (++count < n)
	{
		col[count] = -1;
		sel[count] = 0;
	}

	nq_next_pos(col, sel, 0, n);
	
	free (col);
	free (sel);
	
	return (0);
}
