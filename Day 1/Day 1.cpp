#include <iostream>
#include <vector>
#include <fstream>

/* ADVENT OF CODE DAY 1 */
/* ANDREY LITVINENKO */

int main()
{
	std::ifstream file;
	std::vector<int> data; /* Not the decision I want, but the one I need */
	int numOfIncreases = -1; /* -1 because of a first reading */
	int reading = 0;

	file.open("input");
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open input file" << '\n';
		exit(1);
	}

	while (file >> reading)
	{
		data.push_back(reading);
	}

	file.close();

	/* Part 1 */
	for (int i = 1; i < data.size(); i++)
	{
		if (data[i] > data[i - 1])
		{
			numOfIncreases += 1;
		}
	}

	std::cout << "Part 1" << "\n";
	std::cout << "Total amount of increases: " << numOfIncreases << "\n\n";

	/* Part 2 */
	numOfIncreases = -1;

	int prevSum = 0, sum = 0;

	for (int i = 2; i < data.size(); i++)
	{
		sum = data[i] + data[i - 1] + data[i - 2];

		if (sum > prevSum)
		{
			numOfIncreases += 1;
		}

		prevSum = sum;
	}

	std::cout << "Part 2" << "\n";
	std::cout << "Total amount of increases: " << numOfIncreases << "\n";
}
