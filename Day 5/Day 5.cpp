#include <iostream>
#include <fstream>

/* ADVENT OF CODE DAY 5 */
/* ANDREY LITVINENKO */

void resetMatrix(int** matrix, int matrixSize)
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

int countOverlaps(int** matrix, int matrixSize)
{
	int counter = 0;
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (matrix[i][j] > 1)
			{
				counter += 1;
			}
		}
	}

	return counter;
}

bool beginIsMax(std::pair<int, int> begin,
	std::pair<int, int> end, int pos)
{
	if (pos == 1)
	{
		if (begin.first > end.first)
		{
			return true;
		}
	}

	if (pos == 2)
	{
		if (begin.second > end.second)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	const unsigned int arrSize = 1000;
	std::ifstream file;
	int** matrix = nullptr;

	try
	{
		matrix = new int*[arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			matrix[i] = new int[arrSize];
		}
	}

	catch (std::bad_alloc&)
	{
		std::cerr << "Error: not enough memory" << '\n';
		exit(2);
	}

	resetMatrix(matrix, arrSize);
	std::pair<int, int> begin = std::make_pair(0, 0);
	std::pair<int, int> end = std::make_pair(0, 0);

	file.open("input");
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open input file" << '\n';
		exit(1);
	}

	/* Part 1 */
	while (!file.eof() && file.peek() != EOF)
	{
		int read;
		while (file.peek() != '\n')
		{
			file >> read;
			begin.first = read;
			file.ignore(1, ',');
			file >> read;
			begin.second = read;

			file.ignore(4);	
			file >> read;
			end.first = read;
			file.ignore(1, ',');
			file >> read;
			end.second = read;
		}

		file.ignore(1);

		/* going by y-axis */
		if (begin.first == end.first)
		{
			if (beginIsMax(begin, end, 2))
			{
				for (int i = end.second; i <= begin.second; i++)
				{
					matrix[begin.first][i] += 1;
				}
			}

			else
			{
				for (int i = begin.second; i <= end.second; i++)
				{
					matrix[begin.first][i] += 1;
				}
			}
		}

		/* going by x-axis */
		else if (begin.second == end.second)
		{
			if (beginIsMax(begin, end, 1))
			{
				for (int i = end.first; i <= begin.first; i++)
				{
					matrix[i][begin.second] += 1;
				}
			}

			else
			{
				for (int i = begin.first; i <= end.first; i++)
				{
					matrix[i][begin.second] += 1;
				}
			}
		}
	}

	std::cout << "Part 1" << "\n";
	std::cout << "Amount of overlaps is: " << countOverlaps(matrix, arrSize) << "\n\n";

	/* Part 2 */
	file.clear(); /* Clear EOF flag and error state */
	file.seekg(0); /* Return to the beginning of the file */

	while (!file.eof() && file.peek() != EOF)
	{
		int read;
		while (file.peek() != '\n')
		{
			file >> read;
			begin.first = read;
			file.ignore(1, ',');
			file >> read;
			begin.second = read;

			file.ignore(4);
			file >> read;
			end.first = read;
			file.ignore(1, ',');
			file >> read;
			end.second = read;
		}

		file.ignore(1);

		if (begin.first != end.first && begin.second != end.second)
		{
			if (beginIsMax(begin, end, 1))
			{
				/* going bottom-right */
				if (beginIsMax(begin, end, 2))
				{
					for (int x = end.first, y = end.second;
						x <= begin.first && y <= begin.second; x++, y++)
					{
						matrix[x][y] += 1;
					}
				}

				/* going top-right */
				else
				{
					for (int x = end.first, y = end.second;
						x <= begin.first && y >= begin.second; x++, y--)
					{
						matrix[x][y] += 1;
					}
				}
			}

			else
			{
				/* going bottom-left */
				if (beginIsMax(begin, end, 2))
				{
					for (int x = end.first, y = end.second;
						x >= begin.first && y <= begin.second; x--, y++)
					{
						matrix[x][y] += 1;
					}
				}

				/* going top-left */
				else
				{
					for (int x = end.first, y = end.second;
						x >= begin.first && y >= begin.second; x--, y--)
					{
						matrix[x][y] += 1;
					}
				}
			}
		}
	}

	std::cout << "Part 2" << "\n";
	std::cout << "Amount of overlaps is: " << countOverlaps(matrix, arrSize) << "\n";

	for (int i = 0; i < arrSize; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}
