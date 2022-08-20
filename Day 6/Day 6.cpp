#include <iostream>
#include <vector>
#include <fstream>

/* ADVENT OF CODE DAY 6 */
/* ANDREY LITVINENKO */

int main()
{
	std::ifstream file;
	std::vector<long long> fish;

	file.open("input");
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open input file" << '\n';
		exit(1);
	}

	/* Part 1 */
	while (file.peek() != EOF)
	{
		int read;
		file >> read;
		file.ignore(1, ',');
		fish.push_back(read);
	}

	for (int i = 0; i < 80; i++)
	{
		int newFish = 0;
		for (auto& it : fish)
		{
			if (it == 0)
			{
				it = 6;
				newFish += 1;
			}

			else
			{
				it -= 1;
			}
		}

		for (int j = 0; j < newFish; j++)
		{
			fish.push_back(8);
		}
	}

	std::cout << "Part 1" << "\n";
	std::cout << "Fish amount after 80 days: " << fish.size() << "\n\n";

	/* Part 2 */
	/* Too much calculations and high memory usage,
	this solution will be inefficient for this part */

	file.close();
	return 0;
}
