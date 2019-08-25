#include <iostream>
#include <random>
#include <algorithm>

#include <cmath>

#include "cdarray.hpp"

int main(int argc, char **argv)
{
	CDArray<int> numbers(700);
	int min, max;

	std::cout << "Enter min number value: ";
	std::cin >> min;

	std::cout << "Enter max number value: ";
	std::cin >> max;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);

	for (int i = 0; i < numbers.Size(); i++)
	{
		numbers.Add(dis(gen));
		std::cout << numbers[i] << ' ';
	}
	std::cout << std::endl;


	/* Sort array */
	std::cout << "After sort: " << std::endl;
	std::sort(numbers.Ptr(), numbers.Ptr() + numbers.Number());
	for (int i = 0; i < numbers.Number(); i++)
	{
		std::cout << numbers[i] << ' ';
	}
	std::cout << std::endl;


	/* Calc distribution series */
	CDArray<std::pair<int, double>> distribution;
	int value, count = 0;
	for (int i = 0; i < numbers.Number(); i++)
	{
		if (i == 0 || value != numbers[i])
		{
			if (i != 0)
			{
				distribution.Add(std::make_pair(value, static_cast<double>(count) / numbers.Number()));
			}

			count = 1;
			value = numbers[i];
		}
		else
		{
			count++;
		}
	}
	distribution.Add(std::make_pair(value, static_cast<double>(count) / numbers.Number()));

	std::cout << "Distribution series: " << std::endl;
	for (int i = 0; i < distribution.Number(); i++)
	{
		std::cout << distribution[i].first << "(" << distribution[i].second << ")" << ' ';
	}
	std::cout << std::endl;


	/* Calc expected value */
	double expected_val{0};
	for (int i = 0; i < distribution.Number(); i++)
	{
		expected_val += distribution[i].first * distribution[i].second;
	}

	std::cout << "Expected value: " << expected_val << std::endl;


	/* Calc variance value */
	double variance_val{0};
	for (int i = 0; i < distribution.Number(); i++)
	{
		variance_val += std::pow(distribution[i].first, 2) * distribution[i].second;
	}
	variance_val -= std::pow(expected_val, 2);

	std::cout << "Variance value: " << variance_val << std::endl;


	/* Calc standard deviation value */
	double deviation_val = std::sqrt(variance_val);

	std::cout << "Standard deviation: " << deviation_val << std::endl;

	return 0;
}