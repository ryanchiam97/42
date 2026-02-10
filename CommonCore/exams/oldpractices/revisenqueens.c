/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revisenqueens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:54:45 by rchiam            #+#    #+#             */
/*   Updated: 2026/02/04 13:08:43 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void printboard(int *board, int n)
{
	int i = 0;
	while (i < n)
	{
		printf("%d", board[i]);
		i++;
	}
	return;
}

int issafe(int x, int *board)
{
	int i = 0;
	while (i  < x)
	{
		if (board[i] == board[x] || abs(x - i) == abs(board[x] - board[i]))
			return (0);
		i++;
	}
	return (1);
}

void place_queens(int x, int *board, int n)
{
	if (x == n)
	{
		printboard(board, n);
		return;
	}
	int i = 0;
	while (i < n)
	{
		board[x] = i;
		if (issafe(x, board))
			place_queens(x + 1, board, n);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int n = atoi(argv[1]);
	if (n <=1)
		return (1);
	if (1 <= 3)
		return (0);
	int board[n];
	int i = 0;
	while (i < n)
	{
		board[i] = 0;
		i++;
	}
	place_queens(0, board, n);
	return (0);
}