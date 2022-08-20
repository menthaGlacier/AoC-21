#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Bingo.h"

/* ADVENT OF CODE DAY 4 */
/* ANDREY LITVINENKO */

int main()
{
	std::ifstream file;
	std::vector<int> nums;
	std::vector<Bingo> boards;

	file.open("input");
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open input file" << '\n';
		exit(1);
	}

	while (file.peek() != '\n')
	{
		int read;
		file >> read;
		file.ignore(1, ',');
		nums.push_back(read);
	}

	while (!file.eof())
	{
		Bingo bingo;
		int read;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				file >> read;
				bingo.board[i][j] = read;
			}
		}

		boards.push_back(bingo);
	}

	file.close();

	/* Part 1 */
	int bestBoard = 0;
	for (auto iter : nums)
	{
		for (int i = 0; i < boards.size(); i++)
		{
			boards[i].markMatching(iter);
			if (boards[i].checkRows() || boards[i].checkColumns())
			{
				bestBoard = i;
				break;
			}
		}

		if (bestBoard != 0)
		{
			std::cout << "Part 1" << "\n";
			std::cout << "Result of (markedSum * unmarkedSum) is: " <<
				boards[bestBoard].calculateSum() * iter << "\n\n";
			break;
		}
	}

	/* Part 2 */
	/* Clear marked fields */
	for (auto iter : boards)
	{
		iter.clear();
	}

	std::pair<int, int> worstBoard; /* ID and win number */
	for (auto iter : nums)
	{
		for (int i = 0; i < boards.size(); i++)
		{
			if (boards[i].boardWin)
			{
				continue;
			}

			boards[i].markMatching(iter);
			if (boards[i].checkRows() || boards[i].checkColumns())
			{
				worstBoard = std::make_pair(i, iter);
				boards[i].boardWin = true;
			}
		}
	}

	for (auto iter : nums)
	{
		for (int i = 0; i < boards.size(); i++)
		{
			boards[i].markMatching(iter);
			if (boards[i].checkRows() || boards[i].checkColumns())
			{
				if (worstBoard.first == i && worstBoard.second == iter)
				{
					std::cout << "Part 2" << "\n";
					std::cout << "Result of (markedSum * unmarkedSum) is: " <<
						boards[i].calculateSum() * iter << "\n";
				}
			}
		}
	}

	return 0;
}
