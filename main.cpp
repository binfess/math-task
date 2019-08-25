#include <iostream>
#include <random>

#include "cdarray.hpp"

int main(int argc, char **argv)
{
	CDArray<int> numbers(700);

	int max = 50, min = 10;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);

	for (int i = 0; i < 700; i++)
	{
		numbers.Add(dis(gen));
		std::cout << numbers[i] << std::endl;
	}

	return 0;
}