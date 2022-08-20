#include "Bingo.h"

Bingo::Bingo()
{
	clear();
}

int Bingo::calculateSum()
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

bool Bingo::checkRows()
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

bool Bingo::checkColumns()
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

void Bingo::clear()
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

void Bingo::markMatching(int number)
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
