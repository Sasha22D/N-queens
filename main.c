#include <stdio.h>
#include <stdlib.h> //abs

#define SIZE 10

int	check_col_row(int x, int y, int board[SIZE][SIZE])
{
	int	row,col;

	row = 0;
	col = 0;
	while (col < 10)
	{
		if (board[x][col] == 1)
			return (1);
		col++;
	}
	while (row < 10)
	{
		if (board[row][y] == 1)
			return (1);
		row++;
	}
	return (0);
}

int	check_diagonal(int x, int y, int board[SIZE][SIZE])
{
	int	row, col;

	row = x;
	col = y;
	while (row >= 0 && col >= 0)
	{
		if (board[row--][col--] == 1)
			return (1);
	}
	row = x;
	col = y;
	while (row <= SIZE && col >= 0)
	{
		if (board[row++][col--] == 1)
			return (1);
	}
	row = x;
	col = y;
	while (row <= SIZE && col <= SIZE)
	{
		if (board[row++][col++] == 1)
			return (1);
	}
	row = x;
	col = y;
	while (row >= 0 && col <= SIZE)
	{
		if (board[row--][col++] == 1)
			return (1);
	}
	return (0);
}

int	check_pos(int x, int y, int board[SIZE][SIZE])
{
	if (check_col_row(x, y, board) || check_diagonal(x, y, board))
		return (1);
	else
		return (0);
}

int	main()
{
	int	board[SIZE][SIZE] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //0
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, //1
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //2
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //3
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, //4
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //5
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, //6
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //7
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //8
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //9
//		 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};
	printf("%d\n", check_pos(4, 3, board));
}