#include <stdlib.h>
#include <stdio.h>

void print_board(int n, int *board)
{
    int i;

    i = 0;
    while (i < n)
    {
        printf("%d", board[i]);
        i++;
    }
    printf("\n");
}

int is_safe(int x, int *board)
{
    int i = 0;

    while (i < x)
    {
        if (abs(x - i) == abs(board[x]-board[i]) || board[x] == board[i])
            return (0);
        i++;
    }
    return(1);
}

void place_queens(int x, int *board, int n)
{
    int i = 0;

    if (x == n)
        print_board(n, board);
    else
    {
        while (i < n)
        {
            board[x] = i;
            if (is_safe(x, board))
                place_queens(x + 1, board, n);
            i++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);

    int i = 0;
    int n = atoi(argv[1]);
    if (n <= 1)
        return (1);
    int board[n];
    
    while (i < n)
    {
        board[i] = 0;
        i++;
    }
    place_queens(0, board, n);
    return (0);
}