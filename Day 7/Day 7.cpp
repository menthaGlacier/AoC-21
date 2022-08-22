#include <iostream>
#include <vector>
#include <fstream>

/* ADVENT OF CODE DAY 7 */
/* ANDREY LITVINENKO */

void sort(std::vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size() - 1; j++)
		{
			if (vec[j] > vec[j + 1])
			{
				int temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}

int getAbs(int num)
{
	if (num > 0)
	{
		return num;
	}

	return num * -1;
}

int getMedian(std::vector<int> vec)
{
	sort(vec);
	if (vec.size() % 2 != 0)
	{
		return vec[vec.size() / 2.0f];
	}

	return (vec[(vec.size() - 1) / 2.0f] + vec[vec.size() / 2.0f]) / 2.0f;
}

int getMean(std::vector<int> vec)
{
	int sum = 0;
	for (auto iter : vec)
	{
		sum += iter;
	}

	return sum / vec.size();
}

int main()
{
	std::ifstream file;
	std::vector<int> crabs;
	int fuel = 0;

	file.open("input");
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open input file" << '\n';
		exit(1);
	}

	while (file.peek() != EOF)
	{
		int read;
		file >> read;
		file.ignore(1, ',');
		crabs.push_back(read);
	}

	/* Part 1 */
	/* The center of the numbers series is closer to all the numbers */

	sort(crabs);
	int median = getMedian(crabs);
	for (auto iter : crabs)
	{
		fuel += getAbs(iter - median);
	}

	std::cout << "Part 1" << "\n";
	std::cout << "Fuel consumption: " << fuel << "\n\n";

	/* Part 2 */
	/* As fuel consumption increases in arithmetic progression,
	it is more efficient to "aim" the numbers at the arithmetic mean */

	int mean = getMean(crabs); fuel = 0;
	for (auto iter : crabs)
	{
		/* Arithmetic progression to find the fuel consumption */
		int addRate = getAbs(iter - mean);
		fuel += addRate * (addRate + 1) / 2.0;
	}

	std::cout << "Part 2" << "\n";
	std::cout << "Fuel consumption: " << fuel << "\n";

	file.close();
	return 0;
}
