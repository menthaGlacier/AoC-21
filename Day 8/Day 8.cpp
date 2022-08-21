#include <iostream>
#include <string>
#include <fstream>

/* ADVENT OF CODE DAY 8 */
/* ANDREY LITVINENKO */

enum DigitsLength
{
	_ONE = 2,
	_FOUR = 4,
	_SEVEN = 3,
	_EIGHT = 7
};

int main()
{
	std::ifstream file;
	std::string pattern;

	file.open("input");
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open input file" << '\n';
		exit(1);
	}

	/* Part 1 */
	int digitsAmount = 0;
	while (file.peek() != EOF)
	{
		file.ignore(80, '|');
		while (file.peek() != '\n')
		{
			file >> pattern;

			if (pattern.length() == _ONE || pattern.length() == _FOUR
				|| pattern.length() == _SEVEN || pattern.length() == _EIGHT)
			{
				digitsAmount += 1;
			}
		}

		file.ignore(1);
	}

	std::cout << "Part 1" << "\n";
	std::cout << "Amount of digits 1, 4, 7 or 8: " << digitsAmount << "\n\n";

	file.close();
	return 0;
}
