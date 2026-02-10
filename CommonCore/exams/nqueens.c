#include <stdlib.h>
#include <stdio.h>

void printboard(int *board, int size)
{
	if (!board)
		return ;
	printf("%i", board[0]);
	int i = 1;
	while (i < size)
	{
		printf(" %i", board[i]);
		i++;
	}
	printf("\n");
}

int issafe(int *board, int pos)
{
	int i = 0;
	while (i < pos)
	{
		if (board[i] == board[pos] || i == pos || abs(board[i] - board[pos]) == abs(i - pos))
			return (0);
		i++;
	}
	return (1);
}

void placequeen(int *board, int pos, int n)
{
	if (pos == n)
		return (printboard(board, n));
	int i = 0;
	while (i < n)
	{
		board[pos] = i;
		if (issafe(board, pos))
			placequeen(board, pos + 1, n);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == 0)
		return (1);
	int n = atoi(argv[1]);
	if (n <= 0)
		return (1);
	if (n == 1)
	{
		printf("1\n");
		return (0);
	}
	if (n <= 3)
		return (0);
	int board[n];
	placequeen(board, 0, n);
	return (0);
}