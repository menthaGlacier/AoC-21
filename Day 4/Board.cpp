#include "Board.h"

Board::Board()
{
	clear();
}

int Board::calculateSum()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sum += board[i][j] * (!marked[i][j]);
		}
	}

	return sum;
}

bool Board::checkRows()
{
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;

		for (int j = 0; j < 5; j++)
		{
			sum += marked[i][j];
		}

		if (sum >= 5)
		{
			return true;
		}
	}

	return false;
}

bool Board::checkColumns()
{
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;
		for (int j = 0; j < 5; j++)
		{
			sum += marked[j][i];
		}

		if (sum == 5)
		{
			return true;
		}
	}

	return false;
}

void Board::clear()
{
	boardWin = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			marked[i][j] = false;
		}
	}
}

void Board::markMatching(int number)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (number == board[i][j])
			{
				marked[i][j] = true;
				return;
			}
		}
	}
}
