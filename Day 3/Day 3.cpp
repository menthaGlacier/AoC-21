#include <iostream>
#include <string>
#include <bitset>
#include <fstream>

/* ADVENT OF CODE DAY 3 */
/* ANDREY LITVINENKO */

int main()
{
	const unsigned int codeLength = 12;

	std::ifstream file;
	std::string code;
	int numOfReadings = 0;
	int bitFrequency[codeLength];

	file.open("input");
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open input file" << '\n';
		exit(1);
	}

	for (int i = 0; i < codeLength; i++)
	{
		bitFrequency[i] = 0;
	}

	/* Part 1 */
	while (file >> code)
	{
		numOfReadings += 1;
		std::bitset<codeLength> read(code);

		for (int i = 0; i < codeLength; i++)
		{
			if (read[i] == 1)
			{
				bitFrequency[i] += 1;
			}
		}
	}

	std::bitset<codeLength> gamma, epsilon;
	for (int i = 0; i < codeLength; i++)
	{
		if (bitFrequency[i] > (numOfReadings / 2.0f))
		{
			gamma[i] = 1;
		}

		else
		{
			gamma[i] = 0;
		}
	}

	epsilon = gamma;
	epsilon.flip();

	std::cout << "Part 1" << "\n";
	std::cout << "Result of (gamma * epsilon) is: " <<
		gamma.to_ulong() * epsilon.to_ulong() << "\n\n";

	file.close();
	return 0;
}

/* OLD SOLUTION */

//void flipBits(bool binaryNum[], int numSize)
//{
//	for (int i = 0; i < numSize; i++)
//	{
//		binaryNum[i] = !binaryNum[i];
//	}
//}
//
//int binaryToDecimal(bool binaryNum[], int numSize)
//{
//	int num = 0;
//	for (int i = 0; i < numSize; i++)
//	{
//		num |= static_cast<int>(binaryNum[i]) << (numSize - i - 1);
//	}
//
//	return num;
//}
//
//int main()
//{
//	std::ifstream file;
//	std::string code;
//
//	/* The idea of the solution is to create an array frequency, which stores
//	the frequency of bit 1 at positions in each code. The frequency is compared
//	to the total number of codes: if the frequency is higher than half of the amount
//	of codes, then bit 1 was more frequent, otherwise bit 0 was more frequent.
//	The gamma rate is formed from these bits. Epsilon has flipped bits of gamma rate */
//
//	int* frequency;
//	bool* gammaRate;
//	int numOfReadings = 0;
//
//	file.open("input");
//
//	if (!file.is_open())
//	{
//		std::cerr << "Error: couldn't open input file" << '\n';
//		exit(1);
//	}
//
//	/* Assume that the length of one code is the same as length of all other codes */ 
//	file >> code;
//	static const int codeLength = code.length();
//	
//	frequency = new int[codeLength];
//	if (frequency == nullptr)
//	{
//		std::cerr << "Error: out of memory" << "\n";
//		exit(2);
//	}
//
//	gammaRate = new bool[codeLength];
//	if (gammaRate == nullptr)
//	{
//		std::cerr << "Error: out of memory" << "\n";
//		exit(2);
//	}
//
//	for (int i = 0; i < codeLength; i++)
//	{
//		frequency[i] = 0;
//		gammaRate[i] = false;
//	}
//
//	file.clear(); /* Clear EOF flag and error state if there were any */
//	file.seekg(0); /* Return to the beginning of the file */
//
//	while (file >> code)
//	{
//		numOfReadings += 1;
//		for (int i = 0; i < codeLength; i++)
//		{
//			if (code[i] == '1')
//			{
//				frequency[i] += 1;
//			}
//		}
//	}
//
//	for (int i = 0; i < codeLength; i++)
//	{
//		if (frequency[i] > (numOfReadings / 2.0f))
//		{
//			gammaRate[i] = true;
//		}
//	}
//
//	int result = binaryToDecimal(gammaRate, codeLength);
//	flipBits(gammaRate, codeLength);
//	result *= binaryToDecimal(gammaRate, codeLength);
//
//	std::cout << "Part 1" << "\n";
//	std::cout << "Result of (gamma * epsilon) is: " << result << "\n\n";
//
//	delete[] frequency;
//	delete[] gammaRate;
//
//	file.close();
//	return 0;
//}
