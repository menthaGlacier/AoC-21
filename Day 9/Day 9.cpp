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

int getBasinSize(std::vector<std::vector<char>>& points,
	int column, int row)
{
	/* Directionals check */
	if (column == -1 || column == points.size()
		|| row == -1 || row == points[0].size())
	{
		return 0;
	}

	/* "Wall" and passed points check */
	if (points[column][row] == '9' || points[column][row] == '*')
	{
		return 0;
	}

	points[column][row] = '*'; /* If point was passed, change it to '*' */

	return 1 + getBasinSize(points, column, row + 1) + getBasinSize(points, column, row -1)
		+ getBasinSize(points, column + 1, row) + getBasinSize(points, column - 1, row);
}

/* If new basin is larger that the smallest, place it in the array and sort */
void processLargestBasins(int basins[], int maxBasins, int newBasin)
{
	if (newBasin > basins[0])
	{
		basins[0] = newBasin;
	}

	/* Sorting */
	for (int i = 0; i < maxBasins; i++)
	{
		for (int j = 0; j < maxBasins - 1; j++)
		{
			if (basins[j] > basins[j + 1])
			{
				int temp = basins[j];
				basins[j] = basins[j + 1];
				basins[j + 1] = temp;
			}
		}
	}
}

int main()
{
	/* The task in Part 2 is to find three largest basins */
	const int MAXBASINS = 3;

	std::ifstream file;
	std::vector<std::vector<char>> pointsMatrix;
	std::vector<std::pair<int, int>> lowPoints;

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
	int riskLevel = 0;
	for (int i = 0; i < pointsMatrix.size(); i++)
	{
		for (int j = 0; j < pointsMatrix[0].size(); j++)
		{
			if (isLowPoint(pointsMatrix, i, j))
			{
				lowPoints.push_back({i, j});
				riskLevel += (1 + (pointsMatrix[i][j] - '0'));
			}
		}
	}

	std::cout << "Part 1" << "\n";
	std::cout << "Risk level: " << riskLevel << "\n\n";

	/* Part 2 */
	int largestBasins[MAXBASINS] = {};
	for (auto iter : lowPoints)
	{
		int newBasin = getBasinSize(pointsMatrix, iter.first, iter.second);
		processLargestBasins(largestBasins, MAXBASINS, newBasin);
	}

	std::cout << "Part 1" << "\n";
	std::cout << "Product of three largest basins: " << 
		largestBasins[0] * largestBasins[1] * largestBasins[2] << "n";

	file.close();
	return 0;
}
