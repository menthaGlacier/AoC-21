#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/* ADVENT OF CODE DAY 9 */
/* ANDREY LITVINENKO */

bool isLowPoint(std::vector<std::vector<char>>& points, 
	int column, int row)
{
	/* Left reading */
	if (column != 0)
	{
		if (points[column][row] >= points[column - 1][row])
		//if ((*row2)[i] >= (*row2)[i - 1])
		{
			return false;
		}
	}

	/* Right reading */
	if (column + 1 != points.size())
	{
		if (points[column][row] >= points[column + 1][row])
		{
			return false;
		}
	}

	/* Up reading */
	if (row != 0)
	{
		if (points[column][row] >= points[column][row - 1])
		{
			return false;
		}
	}

	/* Down reading */
	if (row != points[0].size() - 1)
	{
		if (points[column][row] >= points[column][row + 1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	std::ifstream file;
	std::vector<std::vector<char>> pointsMatrix;
	int riskLevel = 0;

	file.open("input");
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open input file" << '\n';
		exit(1);
	}

	std::string read;
	while (file >> read)
	{
		std::vector<char> row;
		for (int i = 0; i < read.length(); i++)
		{
			row.push_back(read[i]);
		}

		pointsMatrix.push_back(row);
	}

	/* Part 1 */
	for (int i = 0; i < pointsMatrix.size(); i++)
	{
		for (int j = 0; j < pointsMatrix[0].size(); j++)
		{
			if (isLowPoint(pointsMatrix, i, j))
			{
				riskLevel += (1 + (pointsMatrix[i][j] - '0'));
			}
		}
	}

	std::cout << "Part 1" << "\n";
	std::cout << "Risk level: " << riskLevel << "\n\n";

	file.close();
	return 0;
}
