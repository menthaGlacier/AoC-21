#include <iostream>
#include <string>
#include <fstream>

/* ADVENT OF CODE DAY 2 */
/* ANDREY LITVINENKO */

int main()
{
	std::ifstream file;
	std::string command;
	int pos = 0, depth = 0, units = 0;

	file.open("input");
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open input file" << '\n';
		exit(1);
	}

	/* Part 1 */
	while (file >> command >> units)
	{
		if (command.compare("forward") == 0)
		{
			pos += units;
		}

		else if (command.compare("down") == 0)
		{
			depth += units;
		}

		else if (command.compare("up") == 0)
		{
			depth -= units;
		}
	}

	std::cout << "Part 1" << "\n";
	std::cout << "Result of (position * depth) is: " << pos * depth << "\n\n";

	/* Part 2 */
	file.clear(); /* Clear EOF flag and error state */
	file.seekg(0); /* Return tot the beginning of the file */

	int aim = 0;
	pos = 0, depth = 0;

	while (file >> command >> units)
	{
		if (command.compare("forward") == 0)
		{
			pos += units;
			depth += (units * aim);
		}

		else if (command.compare("down") == 0)
		{
			aim += units;
		}

		else if (command.compare("up") == 0)
		{
			aim -= units;
		}
	}

	std::cout << "Part 2" << "\n";
	std::cout << "Result of (position * depth) is: " << pos * depth << "\n";

	file.close();
}
