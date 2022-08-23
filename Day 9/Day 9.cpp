#include <iostream>
#include <string>
#include <fstream>

/* ADVENT OF CODE DAY 9 */
/* ANDREY LITVINENKO */


void findRiskLevel(int& riskLevel,
	std::string* row1, std::string* row2, std::string* row3)
{
	if (row2->empty())
	{
		return;
	}

	for (int i = 0; i < row2->size(); i++)
	{
		/* Left reading */
		if (i != 0)
		{
			if ((*row2)[i] >= (*row2)[i - 1])
			{
				continue;
			}
		}

		/* Right reading */
		if (i+1 != row2->size())
		{
			if ((*row2)[i] >= (*row2)[i + 1])
			{
				continue;
			}
		}

		/* Up reading */
		if (!(row1->empty()))
		{
			if ((*row2)[i] >= (*row1)[i])
			{
				continue;
			}
		}

		/* Down reading */
		if (row2->compare(*row3) != 0)
		{
			if ((*row2)[i] >= (*row3)[i])
			{
				continue;
			}
		}

		riskLevel += 1 + ((*row2)[i] - '0');
	}
}

int main()
{
	std::ifstream file;
	std::string row1, row2, row3;
	int riskLevel = 0;

	file.open("input");
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open input file" << '\n';
		exit(1);
	}

	/* Part 1 */
	while (file >> row3)
	{
		findRiskLevel(riskLevel, &row1, &row2, &row3);
		row1 = row2; row2 = row3; /* Transfering old rows */
	}

	findRiskLevel(riskLevel, &row1, &row2, &row3); /* Final risk level search */

	std::cout << "Part 1" << "\n";
	std::cout << "Risk level: " << riskLevel << "\n\n";

	file.close();
	return 0;
}
